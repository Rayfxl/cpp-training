#pragma once
#include <string>
namespace adas
{
struct Pose {
    int x;
    int y;
    char heading;
};

enum class VehicleType {
    SPORTS_CAR,  // 跑车
    BUS,         // 公交车
    OTHER        // 其他
};

class Executor
{
public:
    static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'}, VehicleType carType = VehicleType::OTHER) noexcept;

public:
    Executor(void) = default;
    virtual ~Executor(void) = default;

    Executor(const Executor&) = delete;
    Executor& operator=(const Executor&) = delete;

public:
    virtual void Execute(const std::string& command, VehicleType carType = VehicleType::OTHER) noexcept = 0;
    virtual Pose Query(void) const noexcept = 0;
};
}  // namespace adas
