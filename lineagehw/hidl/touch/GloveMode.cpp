/*
 * Copyright (C) 2019 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "GloveMode.h"

#include <fstream>

namespace vendor {
namespace lineage {
namespace touch {
namespace V1_0 {
namespace kirin659 {

static constexpr const char *kTouchGlovePath = "/sys/touchscreen/touch_glove";

// Methods from ::vendor::lineage::touch::V1_0::IGloveMode follow.
Return<bool> GloveMode::isEnabled() {
    std::ifstream file(kTouchGlovePath);
    int result;

    file >> result;
    return !file.fail() && result > 0;
}

Return<bool> GloveMode::setEnabled(bool enabled) {
    std::ofstream file(kTouchGlovePath);
    file << (enabled ? "1" : "0");
    return !file.fail();
}

}  // namespace kirin659
}  // namespace V1_0
}  // namespace touch
}  // namespace lineage
}  // namespace vendor
