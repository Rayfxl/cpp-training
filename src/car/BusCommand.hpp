#include "Command.hpp"

namespace adas
{
class BusMoveCommand : public MoveCommand
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        const auto action =
            poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
        if (poseHandler.IsFast()) {
            actionGroup.PushAction(action);
        }
        actionGroup.PushAction(action);
        return actionGroup;
    }
};
class BusTurnLeftCommand : public TurnLeftCommand
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        if (poseHandler.IsFast()) {
            const auto fastAction =
                poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(fastAction);  // 快速模式额外一步
        }

        const auto extraAction =
            poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
        actionGroup.PushAction(extraAction);

        const auto turnAction =
            poseHandler.IsReverse() ? ActionType::REVERSE_TURNLEFT_ACTION : ActionType::TURNLEFT_ACTION;
        actionGroup.PushAction(turnAction);

        return actionGroup;
    }
};
class BusTurnRightCommand : public TurnRightCommand
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        if (poseHandler.IsFast()) {
            const auto fastAction =
                poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(fastAction);  // 快速模式额外一步
        }

        const auto extraAction =
            poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
        actionGroup.PushAction(extraAction);

        const auto turnAction =
            poseHandler.IsReverse() ? ActionType::REVERSE_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;
        actionGroup.PushAction(turnAction);

        return actionGroup;
    }
};

}  // namespace adas