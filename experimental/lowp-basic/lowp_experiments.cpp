/*
 * Copyright 2021 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <cassert>
#include <cstdio>
#include <cstdint>

// Compile for x86_64 + ssse3 with:
//     c++ -mssse3 experimental/lowp-basic/lowp_experiments.cpp -o lowp
//
// Compile for aarch64 with (Mac os):
//     c++ experimental/lowp-basic/lowp_experiments.cpp -o lowp
//
// View assembly:
//    dumpobj -d lowp | less

template <int N, typename T> using V = T __attribute__((ext_vector_type(N)));

#if !defined(__clang__)
    static_assert(false, "This only works on clang.");
#endif

#if defined(__SSSE3__)
    #include <immintrin.h>
#endif

#if defined(__ARM_NEON)
    // From section 5.5.5 of the ARM C Language Extensions (ACLE)
    #include <arm_neon.h>
#endif

using Q15 = V<8, uint16_t>;

// A pure C version of the ssse3 intrinsic mm_mulhrs_epi16;
static Q15 simulate_ssse3_mm_mulhrs_epi16(Q15 a, Q15 b) {
    Q15 result;
    auto m = [](int16_t r, int16_t s) {
        const int32_t rounding = 1 << 14;
        int32_t temp = (int32_t)r * (int32_t)s + rounding;
        return (int16_t)(temp >> 15);
    };
    for (int i = 0; i < 8; i++) {
        result[i] = m(a[i], b[i]);
    }
    return result;
}

static void test_mm_mulhrs_epi16_simulation() {
    for (int i = -32768; i < 32768; i++) {
        for (int j = -32768; j < 32768; j++) {
            Q15 a(i);
            Q15 b(j);
            Q15 simResult = simulate_ssse3_mm_mulhrs_epi16(a, b);
            Q15 intrinsicResult = _mm_mulhrs_epi16(a, b);
            for (int i = 0; i < 8; i++) {
                if (simResult[i] != intrinsicResult[i]) {
                    printf("simulate_ssse3_mm_mulhrs_epi16 broken\n");
                    printf("i: %d, a: %hx b: %hx, intrinsic: %hx, sim: %hx\n",
                           i, a[i], b[i], intrinsicResult[i], simResult[i]);
                    exit(1);
                }
            }
        }
    }
}

int main() {
    test_mm_mulhrs_epi16_simulation();
    printf("Done.\n");
    return 0;
}