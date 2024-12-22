#include "CmderFactory.hpp"

namespace adas
{
CmderList CmderFactory::GetCmders(const std::string& commands, VehicleType carType) const noexcept
{
    CmderList cmders;
    for (const auto cmd : ParseCommandString(commands, carType)) {
        const auto it = cmderMap.find(cmd);
        if (it != cmderMap.end()) {
            cmders.push_back(it->second);
        }
    }
    return cmders;
}

std::string CmderFactory::ParseCommandString(std::string_view commands, VehicleType carType) const noexcept
{
    std::string result(commands);
    ReplaceAll(result, "TR", "Z");
    if (carType == VehicleType::SPORTS_CAR) {
        ReplaceAll(result, "M", "A");
        ReplaceAll(result, "L", "D");
        ReplaceAll(result, "R", "G");
    } else if (carType == VehicleType::BUS) {
        ReplaceAll(result, "M", "T");
        ReplaceAll(result, "L", "Y");
        ReplaceAll(result, "R", "U");
    }

    return result;
}
void CmderFactory::ReplaceAll(std::string& inout, std::string_view what, std::string_view with) const noexcept
{
    for (std::string::size_type pos{}; inout.npos != (pos = inout.find(what.data(), pos, what.length()));
         pos += with.length()) {
        inout.replace(pos, what.length(), with.data(), with.length());
    }
}

}  // namespace adas
