
#include <iostream>
#include <filesystem>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

int main() {
	const auto imagePath = "./assets/maze_1.jpg";

	cv::Mat img = cv::imread(imagePath, cv::IMREAD_COLOR);
	if (img.empty()) {
		std::cerr << "Could not load image: " << imagePath << std::endl;
		return 1;
	}

	cv::imshow("image", img);

	cv::waitKey(0);
	cv::destroyAllWindows();

	std::cout << "Maze solved!" << std::endl;

	return 0;
}
