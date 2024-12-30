#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{

// B 指令
TEST(ExecutorReverseTest, should_return_x_minus_1_given_status_is_reverse_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BM");

    const Pose target{-1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_facing_S_given_status_is_reverse_command_is_L_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BL");

    const Pose target{0, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_facing_N_given_status_is_reverse_command_is_R_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BR");

    const Pose target{0, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// BF 指令
TEST(ExecutorReverseTest, should_return_x_minus_2_given_status_is_reversefast_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BFM");

    const Pose target{-2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_facing_S_and_x_minus_1_given_status_is_reversefast_command_is_L_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BFL");

    const Pose target{-1, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_facing_N_and_x_minus_1_given_status_is_reversefast_command_is_R_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    executor->Execute("BFR");

    const Pose target{-1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

// BB 指令
TEST(ExecutorReverseTest, should_return_y_plus_1_given_command_is_BBM_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

    executor->Execute("BBM");

    const Pose target{0, 1, 'N'};
    ASSERT_EQ(target, executor->Query());
}
}// namespace adas