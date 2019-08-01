// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include "MKVMetadata.h"

#include <json/json.h>

namespace open3d {

bool MKVMetadata::ConvertToJsonValue(Json::Value &value) const {
    intrinsics_.ConvertToJsonValue(value);
    value["serial_number_"] = serial_number_;
    value["stream_length_usec"] = stream_length_usec_;
    value["enable_imu"] = enable_imu_;

    return true;
}
bool MKVMetadata::ConvertFromJsonValue(const Json::Value &value) {
    intrinsics_.ConvertFromJsonValue(value);
    serial_number_ = value["serial_number"].asString();
    stream_length_usec_ = value["stream_length_usec"].asUInt64();
    enable_imu_ = value["enable_imu"].asBool();

    return true;
}
}  // namespace open3d
