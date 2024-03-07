#include "sdl_handler.h"

#include "SDL2/SDL_image.h"

#include "exceptions/sdl_exception.h"

SDLHandler &SDLHandler::getInstance() {
	static SDLHandler sdlHandler;
	return sdlHandler;
}

SDLHandler::SDLHandler() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		throw SDLException(SDL_GetError());
	}

	auto imageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	if (IMG_Init(imageFlags) != imageFlags) {
		throw SDLException(IMG_GetError());
	}

	if (SDL_CreateWindowAndRenderer(1024, 768, SDL_WINDOW_SHOWN, &window, &renderer) != 0) {
		throw SDLException(SDL_GetError());
	}
}

SDLHandler::~SDLHandler() {
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

Image SDLHandler::loadImage(const std::string &filePath) {
	auto image = Image(renderer, filePath);
	return image;
}

void SDLHandler::showImage(Image &image) {
	if (SDL_RenderCopy(renderer, image.texture, nullptr, nullptr) != 0) {
		throw SDLException(SDL_GetError());
	}
}

SDL_Rect SDLHandler::showImageKeepRatio(Image &image) {
	auto imageRatio = double(image.h) / image.w;

	int windowWidth, windowHeight;
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);
	auto windowRatio = double(windowHeight) / windowWidth;

	int newWidth, newHeight;
	if (imageRatio > windowRatio) {
		newHeight = windowHeight;
		newWidth = (double(newHeight) / windowHeight) * image.w;
	} else {
		newWidth = windowWidth;
		newHeight = (double(newWidth) / windowWidth) * image.h;
	}

	SDL_Rect destRect{(windowWidth - newWidth) / 2, (windowHeight - newHeight) / 2, newWidth, newHeight};
	if (SDL_RenderCopy(renderer, image.texture, nullptr, &destRect) != 0) {
		throw SDLException(SDL_GetError());
	}

	return destRect;
}

std::tuple<int, int>
SDLHandler::getClickPositionInImage(
		std::tuple<int, int> clickPosition,
		SDL_Rect displayImageRect,
		Image &originalImage) {
	std::tuple<int, int> clickPositionInImage = {
			std::get<0>(clickPosition) - displayImageRect.x,
			std::get<1>(clickPosition) - displayImageRect.y,
	};

	return {std::get<0>(clickPositionInImage) * ((double) originalImage.w / displayImageRect.w),
					std::get<1>(clickPositionInImage) * ((double) originalImage.h / displayImageRect.h)};
}

void SDLHandler::update() {
	SDL_RenderPresent(renderer);
}

void SDLHandler::setWindowCaption(const std::string &caption) {
	SDL_SetWindowTitle(window, caption.c_str());
}
