#ifndef MAZESOLVER_POINT_H
#define MAZESOLVER_POINT_H

#include <iostream>

struct Point {
	int x, y;
};

std::ostream &operator<<(std::ostream &output, const Point &H);

#endif //MAZESOLVER_POINT_H
