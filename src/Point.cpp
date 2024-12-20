#include "Point.hpp"

namespace adas
{

// 构造函数
Point::Point(const int x, const int y) noexcept
    : x(x), y(y) {}

// 拷贝构造函数
Point::Point(const Point& rhs) noexcept
    : x(rhs.x), y(rhs.y) {}

// 拷贝赋值运算符
Point& Point::operator=(const Point& rhs) noexcept
{
    if (this != &rhs) { // 检查自我赋值
        x = rhs.x;
        y = rhs.y;
    }
    return *this;
}

// += 运算符重载
Point& Point::operator+=(const Point& rhs) noexcept
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

// 获取 x 值
int Point::GetX(void) const noexcept
{
    return x;
}

// 获取 y 值
int Point::GetY(void) const noexcept
{
    return y;
}

} // namespace adas