/** @file
    @brief Implementation

    @date 2016

    @author
    Sensics, Inc.
    <http://sensics.com>

*/

// Copyright 2016 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Internal Includes
#include <osvr/Util/Log.h>
#include <osvr/Util/LogSinks.h>

// Library/third-party includes
#include <spdlog/spdlog.h>

// Standard includes
#include <memory>           // for std::make_shared, std::shared_ptr
#include <string>           // for std::string

namespace osvr {
namespace util {
namespace log {

std::shared_ptr<Logger> make_logger(const std::string& logger_name)
{
    // FIXME use custom OSVR sink that splits output to STDOUT and STDERR and
    // log files based on severity levels, etc.
    auto sink = std::make_shared<stdout_sink_mt>();
    auto spd_logger = std::make_shared<::spdlog::logger>(logger_name, sink);
    return std::make_shared<Logger>(spd_logger);
}

} // end namespace log
} // end namespace util
} // end namespace osvr

