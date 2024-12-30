#pragma once
#include <functional>
#include <list>
#include <string_view>
#include <unordered_map>

#include "ActionGroup.hpp"
#include "BusCommand.hpp"
#include "Command.hpp"
#include "SportsCarCommand.hpp"

namespace adas
{
using Cmder = std::function<ActionGroup(PoseHandler& poseHandler)>;
using CmderList = std::list<Cmder>;
class CmderFactory final
{
public:
    CmderFactory(void) noexcept = default;
    ~CmderFactory(void) noexcept = default;
    CmderFactory(const CmderFactory&) noexcept = delete;
    CmderFactory& operator=(const CmderFactory&) noexcept = delete;

public:
    CmderList GetCmders(const std::string& commands, VehicleType carType = VehicleType::OTHER) const noexcept;

private:
    std::string ParseCommandString(std::string_view commands, VehicleType carType = VehicleType::OTHER) const noexcept;
    void ReplaceAll(std::string& inout, std::string_view what, std::string_view with) const noexcept;

private:
    const std::unordered_map<char, Cmder> cmderMap{
        {'M', MoveCommand()},          {'L', TurnLeftCommand()},          {'R', TurnRightCommand()},
        {'F', FastCommand()},          {'B', ReverseCommand()},           {'Z', TurnRoundCommand()},
        {'A', SportsCarMoveCommand()}, {'D', SportsCarTurnLeftCommand()}, {'G', SportsCarTurnRightCommand()},
        {'T', BusMoveCommand()},       {'Y', BusTurnLeftCommand()},       {'U', BusTurnRightCommand()},
    };
};
}  // namespace adas
