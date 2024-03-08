
#include <iostream>
#include <tuple>

#include "sdl_handler.h"
#include "maze_solver.h"
#include "image.h"
#include "point.h"

const auto windowName = "MazeSolver";
const auto imagePath = "assets/maze_1.jpg";

enum state {
	STATE_START,
	STATE_GET_START_POINT,
	STATE_GET_END_POINT,
	STATE_CALCULATE_PATH,
	STATE_FOUND_PATH,
	STATE_DIDNT_FIND_PATH,
	STATE_WAITING_FOR_CLOSE,
};

std::ostream &operator<<(std::ostream &os, const SDL_Rect &rect) {
	return os << "(" << rect.x << ", " << rect.y << ", " << rect.w << ", " << rect.h << ")";
}

int main() {
	auto sdlHandler = SDLHandler::getInstance();
	sdlHandler.setWindowCaption(windowName);

	MazeSolver mazeSolver;

	auto image = sdlHandler.loadImage(imagePath);

	auto imageDisplayRect = sdlHandler.showImageKeepRatio(image);

	sdlHandler.update();

	SDL_Event event;

	Point startPoint{-1, -1}, endPoint{-1, -1};
	std::vector<Point> path;

	auto currentState = STATE_GET_START_POINT;
	std::cout << "Click on start point" << std::endl;

	while (true) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return 0;
			}

			if (currentState == STATE_WAITING_FOR_CLOSE) {
				continue;
			}

			if (event.type == SDL_KEYDOWN)
				if (event.key.keysym.sym == SDLK_q)
					return 0;

			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (currentState == STATE_GET_START_POINT) {
					startPoint = {event.button.x, event.button.y};
					currentState = STATE_GET_END_POINT;
					std::cout << "Click on end point" << std::endl;
				} else if (currentState == STATE_GET_END_POINT) {
					endPoint = {event.button.x, event.button.y};
					currentState = STATE_CALCULATE_PATH;
					std::cout << "Calculating path" << std::endl;
				}
			}
		}

		if (currentState == STATE_CALCULATE_PATH) {
			auto startPointInImage = sdlHandler.getPointPositionInImage(startPoint, imageDisplayRect, image);
			auto endPointInImage = sdlHandler.getPointPositionInImage(endPoint, imageDisplayRect, image);

			path = mazeSolver.Solve(imagePath, startPointInImage, endPointInImage);

			if (path.empty()) {
				currentState = STATE_DIDNT_FIND_PATH;
				std::cout << "No paths found" << std::endl;
			} else {
				currentState = STATE_FOUND_PATH;
				std::cout << "Found path!" << std::endl;
			}
		}

		if (currentState == STATE_DIDNT_FIND_PATH) {
			break;
		}

		if (currentState == STATE_FOUND_PATH) {
			sdlHandler.setColor(255, 0, 0, 255);

			for (size_t i = 0; i < path.size() - 1; i++) {
				auto p1 = path.at(i), p2 = path.at(i + 1);
				sdlHandler.drawLine(
						sdlHandler.getPointPositionInScreen(p1, imageDisplayRect, image),
						sdlHandler.getPointPositionInScreen(p2, imageDisplayRect, image)
				);
			}

			sdlHandler.update();

			currentState = STATE_WAITING_FOR_CLOSE;
		}
	}

}
