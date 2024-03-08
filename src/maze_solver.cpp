
#include "maze_solver.h"

#include <iostream>

#include <opencv2/opencv.hpp>

#include "exceptions/opencv_exception.h"

std::vector<Point> MazeSolver::Solve(
		const std::string &filePath,
		Point &startPoint,
		Point &endPoint) {
	auto image = cv::imread(filePath, cv::IMREAD_GRAYSCALE);
	if (image.empty()) {
		throw OpenCvException("could not load image " + filePath);
	}

	// get maze boundaries
	auto imageBoundaries = getImageBoundaries(image);

	// extract colors and create a grid vector from them
	auto grid = buildGridVector(image);

	// run a grid-finding algorithm
	auto path = getPath(grid, startPoint, endPoint);

	// return the path
	return path;
}

std::tuple<Point, Point> MazeSolver::getImageBoundaries(cv::Mat &image) {
	return {Point{0, 0}, Point{image.cols, image.rows}};
}

MazeSolver::Grid MazeSolver::buildGridVector(cv::Mat &image) {
	Grid returnValue = Grid(image.rows, GridRow(image.cols));

	for (auto i = 0; i < image.rows; i++) {
		for (auto j = 0; j < image.cols; j++) {
			auto color = image.at<uchar>(i, j);

			returnValue.at(i).at(j) = color > 127;
		}
	}

	return returnValue;
}

std::vector<Point> MazeSolver::getPath(const Grid &grid, Point &startPoint, Point &endPoint) {
	auto rows = grid.size();
	if (rows == 0) return {}; // Empty grid

	auto cols = grid[0].size();
	if (cols == 0) return {}; // Empty grid

	std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
	std::vector<std::vector<Point>> parent(rows, std::vector<Point>(cols, {-1, -1}));

	std::queue<Point> q;
	q.push(startPoint);
	visited[startPoint.y][startPoint.x] = true;

	while (!q.empty()) {
		Point current = q.front();
		q.pop();

		if (current == endPoint) {
			// Found the destination, backtrack to construct the path
			std::vector<Point> path;
			while (current != startPoint) {
				path.push_back(current);
				current = parent[current.y][current.x];
			}
			path.push_back(startPoint);
			std::reverse(path.begin(), path.end());

			return path;
		}

		// Explore adjacent cells
		std::vector<Point> neighbors = {{current.x - 1, current.y},
																		{current.x + 1, current.y},
																		{current.x,     current.y - 1},
																		{current.x,     current.y + 1}};
		for (const auto &neighbor: neighbors) {
			int nx = neighbor.x, ny = neighbor.y;
			if (nx >= 0 && nx < cols && ny >= 0 && ny < rows && grid[ny][nx] && !visited[ny][nx]) {
				visited[ny][nx] = true;
				parent[ny][nx] = current;
				q.push({nx, ny});
			}
		}
	}

	// No path found
	return {};
}
