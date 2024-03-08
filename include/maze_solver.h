#ifndef MAZESOLVER_MAZE_SOLVER_H
#define MAZESOLVER_MAZE_SOLVER_H

#include <tuple>

#include "opencv2/opencv.hpp"

#include "point.h"

class MazeSolver {
public:
	void Solve(const std::string &, Point &, Point &);

private:
	std::tuple<Point, Point> getImageBoundaries(cv::Mat &);
};

#endif //MAZESOLVER_MAZE_SOLVER_H
