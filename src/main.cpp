
#include <iostream>
#include <tuple>

#include "SDLHandler.h"
#include "image.h"

const auto windowName = "window";
const auto imagePath = "assets/maze_1.jpg";

enum state {
	STATE_START,
	STATE_GET_START_POINT,
	STATE_GET_END_POINT,
	STATE_CALCULATE_PATH,
	STATE_END,
};

std::ostream &operator<<(std::ostream &os, const std::tuple<int, int> &t) {
	return os << "(" << std::get<0>(t) << ", " << std::get<1>(t) << ")";
}

std::ostream &operator<<(std::ostream &os, const SDL_Rect &rect) {
	return os << "(" << rect.x << ", " << rect.y << ", " << rect.w << ", " << rect.h << ")";
}

int main() {
	auto sdlHandler = SDLHandler::getInstance();
	sdlHandler.setWindowCaption(windowName);

	auto image = sdlHandler.loadImage(imagePath);

	auto imageDisplayRect = sdlHandler.showImageKeepRatio(image);

	sdlHandler.update();

	SDL_Event event;

	std::tuple<int, int> startPoint{-1, -1}, endPoint{-1, -1};

	auto currentState = STATE_GET_START_POINT;
	std::cout << "Click on start point" << std::endl;

	while (true) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return 0;
			}

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
			std::cout << "calculating path from "
								<< sdlHandler.getClickPositionInImage(startPoint, imageDisplayRect, image)
								<< " to "
								<< sdlHandler.getClickPositionInImage(endPoint, imageDisplayRect, image)
								<< std::endl;
			currentState = STATE_END;
		}

		if (currentState == STATE_END) {
			break;
		}
	}

}
