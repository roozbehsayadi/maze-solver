
#include "point.h"

std::ostream &operator<<(std::ostream &os, const Point &p) {
	return os << '(' << p.x << ", " << p.y << ')';
}

bool Point::operator==(const Point &other) const {
	return x == other.x && y == other.y;
}

bool Point::operator!=(const Point &other) const {
	return x != other.x || y != other.y;
}
