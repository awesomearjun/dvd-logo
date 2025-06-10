#pragma once

#include <iostream>
#include <ostream>

struct Vector2D
{
    int x, y;
    Vector2D() = default;
    Vector2D(int p_x, int p_y) : x(p_x), y(p_y) {}
	friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec)
	{
		os << "Vector2D(" << vec.x << ", " << vec.y << ");";
		return os;
	}
};
