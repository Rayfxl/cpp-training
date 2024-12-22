#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"

namespace adas
{
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& pose, VehicleType carType = VehicleType::OTHER) noexcept;
    ~ExecutorImpl() noexcept = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

public:
    void Execute(const std::string& command, VehicleType carType = VehicleType::OTHER) noexcept override;
    Pose Query(void) const noexcept override;

private:
    PoseHandler poseHandler;
    VehicleType carType;
};
}  // namespace adas
