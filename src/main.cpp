
#include <tuple>

#include "SDLHandler.h"
#include "image.h"

const auto windowName = "window";
const auto imagePath = "assets/maze_1.jpg";

int main() {
	auto sdlHandler = SDLHandler::getInstance();
	sdlHandler.setWindowCaption(windowName);

	auto image = sdlHandler.loadImage(imagePath);

	sdlHandler.showImageKeepRatio(image);
	sdlHandler.update();

	SDL_Event event;
	while (true) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return 0;
			}
		}
	}

}
