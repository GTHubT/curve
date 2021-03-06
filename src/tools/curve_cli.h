/*
 *  Copyright (c) 2020 NetEase Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*
 * Project: curve
 * Created Date: 18-8-27
 * Author: wudemiao
 */

#ifndef SRC_TOOLS_CURVE_CLI_H_
#define SRC_TOOLS_CURVE_CLI_H_

#include <gflags/gflags.h>
#include <butil/string_splitter.h>
#include <braft/cli.h>
#include <braft/configuration.h>

#include <map>
#include <string>
#include <iostream>

#include "src/chunkserver/copyset_node.h"
#include "src/chunkserver/cli2.h"
#include "src/tools/curve_tool.h"
#include "src/tools/curve_tool_define.h"

namespace curve {
namespace tool {
class CurveCli : public CurveTool {
 public:
    /**
     *  @brief 打印help信息
     *  @param 无
     *  @return 无
     */
    void PrintHelp(const std::string &cmd) override;

    /**
     *  @brief 执行命令
     *  @param cmd：执行的命令
     *  @return 成功返回0，失败返回-1
     */
    int RunCommand(const std::string &cmd) override;

    /**
     *  @brief 返回是否支持该命令
     *  @param command：执行的命令
     *  @return true / false
     */
    static bool SupportCommand(const std::string& command);

 private:
    /**
     *  @brief 删除peer
     *  @param 无
     *  @return 成功返回0，失败返回-1
     */
    int RemovePeer();

    /**
     *  @brief 转移leader
     *  @param 无
     *  @return 成功返回0，失败返回-1
     */
    int TransferLeader();

    /**
     *  @brief 重置配置组成员，目前只支持reset成一个成员
     *  @param 无
     *  @return 成功返回0，失败返回-1
     */
    int ResetPeer();
};
}  // namespace tool
}  // namespace curve

#endif  // SRC_TOOLS_CURVE_CLI_H_
