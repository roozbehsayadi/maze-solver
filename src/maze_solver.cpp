
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
	auto image = cv::imread(filePath, cv::IMREAD_GRAYSCALE);
	if (image.empty()) {
		throw OpenCvException("could not load image " + filePath);
	}

	// get maze boundaries
	auto imageBoundaries = getImageBoundaries(image, startPoint);

	// extract colors and create a vector from them

	// run a path-finding algorithm

	// return the path (or display it?)

	cv::imshow("window name", image);

	cv::waitKey();
}

std::tuple<Point, Point> MazeSolver::getImageBoundaries(cv::Mat &image, Point &point) {
	return {Point{0, 0}, Point{image.cols, image.rows}};
}
