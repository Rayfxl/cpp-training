#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{

// 定义测试参数结构体
struct VehicleTestParam {
    VehicleType carType;   // 车辆类型：跑车 or Bus
    Pose initialPose;      // 初始状态
    std::string commands;  // 执行的指令
    Pose expectedPose;     // 预期的状态
};

// 使用 TestWithParam 定义数据驱动测试类
class VehicleCommandTest : public ::testing::TestWithParam<VehicleTestParam>
{
};

// 通用测试逻辑
TEST_P(VehicleCommandTest, ExecuteCommands)
{
    const auto& param = GetParam();

    // 初始化 Executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor(param.initialPose, param.carType));

    // 执行命令
    executor->Execute(param.commands, param.carType);

    // 验证结果
    ASSERT_EQ(param.expectedPose, executor->Query());
}

// 定义测试数据
INSTANTIATE_TEST_SUITE_P(VehicleCommandTests, VehicleCommandTest,
                         ::testing::Values(
                             // 跑车 - Normal 模式
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "M", {2, 0, 'E'}},
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "L", {0, 1, 'N'}},
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "R", {0, -1, 'S'}},

                             // 跑车 - B 模式
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "BM", {-2, 0, 'E'}},
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "BL", {0, 1, 'S'}},
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "BR", {0, -1, 'N'}},

                             // 跑车 - F 模式
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "FM", {4, 0, 'E'}},
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "FL", {1, 1, 'N'}},
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "FR", {1, -1, 'S'}},

                             // 跑车 - B&F 模式
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "BFM", {-4, 0, 'E'}},
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "BFL", {-1, 1, 'S'}},
                             VehicleTestParam{VehicleType::SPORTS_CAR, {0, 0, 'E'}, "BFR", {-1, -1, 'N'}},

                             // Bus - Normal 模式
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "M", {1, 0, 'E'}},
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "L", {1, 0, 'N'}},
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "R", {1, 0, 'S'}},

                             // Bus - B 模式
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "BM", {-1, 0, 'E'}},
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "BL", {-1, 0, 'S'}},
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "BR", {-1, 0, 'N'}},

                             // Bus - F 模式
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "FM", {2, 0, 'E'}},
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "FL", {2, 0, 'N'}},
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "FR", {2, 0, 'S'}},

                             // Bus - B&F 模式
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "BFM", {-2, 0, 'E'}},
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "BFL", {-2, 0, 'S'}},
                             VehicleTestParam{VehicleType::BUS, {0, 0, 'E'}, "BFR", {-2, 0, 'N'}}));

}  // namespace adas
