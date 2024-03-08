#ifndef MAZESOLVER_MAZE_SOLVER_H
#define MAZESOLVER_MAZE_SOLVER_H

#include <tuple>
#include <vector>

#include "opencv2/opencv.hpp"

#include "point.h"

class MazeSolver {
public:
	std::vector<Point> Solve(const std::string &, Point &, Point &);

private:
	typedef std::vector<bool> GridRow;
	typedef std::vector<GridRow> Grid;

	static std::tuple<Point, Point> getImageBoundaries(cv::Mat &);

	static Grid buildGridVector(cv::Mat &image);

	static std::vector<Point> getPath(const Grid &, Point &, Point &);
};

#endif //MAZESOLVER_MAZE_SOLVER_H
