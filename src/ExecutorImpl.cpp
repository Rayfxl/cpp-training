#include <memory>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include "ExecutorImpl.hpp"
#include "Command.hpp"
#include "CmderFactory.hpp"
#include "Singleton.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : poseHandler(pose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);


    std::for_each(
        cmders.begin(), cmders.end(),
        [this](const Cmder& cmder) noexcept { cmder(poseHandler); });

}

Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}
}// namespace adas
