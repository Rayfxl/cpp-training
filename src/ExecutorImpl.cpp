#include "ExecutorImpl.hpp"

#include <algorithm>
#include <functional>
#include <memory>
#include <unordered_map>

#include "CmderFactory.hpp"
#include "Singleton.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose, VehicleType carType) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose, carType);
}

ExecutorImpl::ExecutorImpl(const Pose& pose, VehicleType carType) noexcept : poseHandler(pose), carType(carType)
{
}

void ExecutorImpl::Execute(const std::string& commands, VehicleType carType) noexcept
{
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands, carType);

    std::for_each(cmders.begin(), cmders.end(),
                  [this](const Cmder& cmder) noexcept { cmder(poseHandler).DoOperate(poseHandler); });
}

Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}
}  // namespace adas
