
#include "maze_solver.h"

#include <iostream>

MazeSolver &MazeSolver::getInstance() {
	static MazeSolver mazeSolver;
	return mazeSolver;
}

void MazeSolver::Solve(
		const std::string &filePath,
		Point &startPoint,
		Point &endPoint) {
	std::cout << "Found the path from " << startPoint << " to " << endPoint << std::endl;
}
