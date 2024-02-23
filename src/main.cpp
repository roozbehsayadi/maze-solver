
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

enum stateEnum {
	STATE_UNKNOWN = 0,
	STATE_WAIT_FOR_START_POINT = 1,
	STATE_WAIT_FOR_DESTINATION_POINT = 2,
	STATE_COMPUTING = 3,
	STATE_FOUND_THE_ANSWER = 4
};

volatile stateEnum state = STATE_UNKNOWN;

const auto imagePath = "./assets/maze_1.jpg";
const auto windowName = "window";

int startX, startY;
int destX, destY;

void mouseCallback(int event, int x, int y, int flags, void *userdata) {
	if (event == cv::EVENT_LBUTTONDOWN) {
		if (state == STATE_WAIT_FOR_START_POINT) {
			startX = x;
			startY = y;
			state = STATE_WAIT_FOR_DESTINATION_POINT;
		} else if (state == STATE_WAIT_FOR_DESTINATION_POINT) {
			destX = x;
			destY = y;
			state = STATE_COMPUTING;
		}
	}
}

int main() {
	cv::Mat img = cv::imread(imagePath, cv::IMREAD_COLOR);
	if (img.empty()) {
		std::cerr << "Could not load image: " << imagePath << std::endl;
		return 1;
	}

	cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
	cv::imshow(windowName, img);

	state = STATE_WAIT_FOR_START_POINT;

	cv::setMouseCallback(windowName, mouseCallback);

	std::cout << "Click on two points to set start and destination points" << std::endl;
	std::cout << "Press q to quit" << std::endl;

	while (cv::waitKey(1) != 'q') {
		if (state == STATE_COMPUTING) {
			std::cout << "Start point: " << startX << ", " << startY << std::endl;
			std::cout << "Destination point: " << destX << ", " << destY << std::endl;
			state = STATE_FOUND_THE_ANSWER;
		}

		if (state == STATE_FOUND_THE_ANSWER) {
			std::cout << "Found the answer!" << std::endl;
			break;
		}
	}

	std::cout << "Program is ended!" << std::endl;

	cv::destroyAllWindows();

	return 0;
}
