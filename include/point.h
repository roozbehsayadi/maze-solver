#ifndef MAZESOLVER_POINT_H
#define MAZESOLVER_POINT_H

#include <iostream>

struct Point {
	int x, y;

	bool operator==(const Point &) const;
	bool operator!=(const Point &) const;
};

std::ostream &operator<<(std::ostream &output, const Point &H);

#endif //MAZESOLVER_POINT_H
