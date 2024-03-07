#ifndef MAZESOLVER_MAZE_SOLVER_H
#define MAZESOLVER_MAZE_SOLVER_H

#include <tuple>

#include "point.h"

class MazeSolver {
public:
	static MazeSolver &getInstance();

	void Solve(const std::string &, Point &, Point &);

private:
};

#endif //MAZESOLVER_MAZE_SOLVER_H
