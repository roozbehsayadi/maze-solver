
#include "maze_solver.h"

#include <iostream>

#include <opencv2/opencv.hpp>

#include "exceptions/opencv_exception.h"

MazeSolver &MazeSolver::getInstance() {
	static MazeSolver mazeSolver;
	return mazeSolver;
}

void MazeSolver::Solve(
		const std::string &filePath,
		Point &startPoint,
		Point &endPoint) {
	auto image = cv::imread(filePath, cv::IMREAD_COLOR);
	if (image.empty()) {
		throw OpenCvException("could not load image " + filePath);
	}

	// get maze boundaries

	// extract colors and create a vector from them

	// run a path-finding algorithm

	// return the path (or display it?)

	cv::imshow("window name", image);

	cv::waitKey();
}
