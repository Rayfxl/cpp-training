#pragma once
#include <functional>
#include "PoseHandler.hpp"

namespace adas
{
// class ICommand
// {
// public:
//     virtual ~ICommand() = default;
//     virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
// };

class MoveCommand final
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override
    // {
    //     if (poseHandler.IsFast()) {
    //         poseHandler.Move();
    //     }
    //     poseHandler.Move();
    // }
    const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.Move();
    };

};
class TurnLeftCommand final
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override
    // {
    //     if (poseHandler.IsFast()) {
    //         poseHandler.Move();
    //     }
    //     poseHandler.TurnLeft();
    // }
    const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.TurnLeft();
    };
};
class TurnRightCommand final
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override
    // {
    //     if (poseHandler.IsFast()) {
    //         poseHandler.Move();
    //     }
    //     poseHandler.TurnRight();
    // }
    const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.TurnRight();
    };

};
class FastCommand final
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override
    // {
    //     poseHandler.Fast();
    // }
    const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
        poseHandler.Fast();
    };

};
}// namespace adas