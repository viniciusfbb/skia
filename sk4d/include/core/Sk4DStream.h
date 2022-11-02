/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef Sk4DStream_DEFINED
#define Sk4DStream_DEFINED

#include "include/core/SkStream.h"

class SkStreamAdapter final : public SkStreamAsset {
public:
    struct Procs {
        size_t (*fGetLength)   (void* context);
        size_t (*fGetPosition) (void* context);
        size_t (*fRead)        (void* context, void* buffer, size_t size);
        bool   (*fSeek)        (void* context, size_t position);
    };

    static void setProcs(const Procs& procs);

public:
    SkStreamAdapter(void* context);

    size_t getLength() const override;
    size_t getPosition() const override;
    bool isAtEnd() const override;
    bool move(long offset) override;
    size_t peek(void* buffer, size_t size) const override;
    size_t read(void* buffer, size_t size) override;
    bool rewind() override;
    bool seek(size_t position) override;

private:
    SkStreamAsset* onDuplicate() const override;
    SkStreamAsset* onFork() const override;

private:
    void*        fContext;
    static Procs fProcs;

    using INHERITED = SkStreamAsset;
};

class SkWStreamAdapter final : public SkWStream {
public:
    struct Procs {
        bool (*fWrite)   (void* context, const void* buffer, size_t size);
    };

    static void setProcs(const Procs& procs);

public:
    SkWStreamAdapter(void* context);

    size_t bytesWritten() const override;
    void flush() override;
    bool write(const void* buffer, size_t size) override;

private:
    void*        fContext;
    size_t       fBytesWritten;
    static Procs fProcs;

    using INHERITED = SkWStream;
};

#endif
