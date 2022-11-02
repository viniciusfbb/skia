/*
 * Copyright (c) 2011-2022 Google LLC.
 * Copyright (c) 2021-2022 Skia4Delphi Project.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkData.h"
#include "include/core/Sk4DStream.h"

SkStreamAdapter::Procs SkStreamAdapter::fProcs;

SkStreamAdapter::SkStreamAdapter(void* context) : fContext(context) {
}

size_t SkStreamAdapter::getLength() const {
    return fProcs.fGetLength(fContext);
}

size_t SkStreamAdapter::getPosition() const {
    return fProcs.fGetPosition(fContext);
}

bool SkStreamAdapter::isAtEnd() const {
    return this->getPosition() == this->getLength();
}

bool SkStreamAdapter::move(long offset) {
    return this->seek(this->getPosition() + offset);
}

size_t SkStreamAdapter::peek(void* buffer, size_t size) const {
    auto currentOffset = this->getPosition();
    auto nonConstThis  = const_cast<SkStreamAdapter*>(this);
    auto bytesRead     = nonConstThis->read(buffer, size);
    nonConstThis->seek(currentOffset);
    return bytesRead;
}

size_t SkStreamAdapter::read(void* buffer, size_t size) {
    return fProcs.fRead(fContext, buffer, size);
}

bool SkStreamAdapter::rewind() {
    return this->seek(0);
}

bool SkStreamAdapter::seek(size_t position) {
    return fProcs.fSeek(fContext, position);
}

SkStreamAsset* SkStreamAdapter::onDuplicate() const {
    auto data          = SkData::MakeUninitialized(this->getLength());
    auto currentOffset = this->getPosition();
    auto nonConstThis  = const_cast<SkStreamAdapter*>(this);
    nonConstThis->rewind();
    auto bytesRead = nonConstThis->read(data->writable_data(), data->size());
    nonConstThis->seek(currentOffset);
    if (bytesRead != data->size())
        return nullptr;
    return new SkMemoryStream(data);
}

SkStreamAsset* SkStreamAdapter::onFork() const {
    std::unique_ptr<SkStreamAsset> that(this->duplicate());
    that->seek(this->getPosition());
    return that.release();
}

void SkStreamAdapter::setProcs(const Procs& procs) {
    fProcs = procs;
}

SkWStreamAdapter::Procs SkWStreamAdapter::fProcs;

SkWStreamAdapter::SkWStreamAdapter(void* context)
    : fContext(context)
    , fBytesWritten(0)
{
}

size_t SkWStreamAdapter::bytesWritten() const {
    return fBytesWritten;
}

void SkWStreamAdapter::flush() {
}

void SkWStreamAdapter::setProcs(const Procs& procs) {
    fProcs = procs;
}

bool SkWStreamAdapter::write(const void* buffer, size_t size) {
    if (!fProcs.fWrite(fContext, buffer, size))
        return false;
    fBytesWritten += size;
    return true;
}
