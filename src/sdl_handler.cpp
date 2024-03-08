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

	if (imageRatio == windowRatio) {
		newWidth = windowWidth;
		newHeight = windowHeight;
	} else if (imageRatio > windowRatio) {
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

void SDLHandler::setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void SDLHandler::drawLine(const Point &p1, const Point &p2) {
	SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
}

Point SDLHandler::getPointPositionInImage(
		const Point &point,
		SDL_Rect displayImageRect,
		Image &originalImage) {
	Point positionInImage = {
			point.x - displayImageRect.x,
			point.y - displayImageRect.y,
	};

	return {static_cast<int>(positionInImage.x * ((double) originalImage.w / displayImageRect.w)),
					static_cast<int>(positionInImage.y * ((double) originalImage.h / displayImageRect.h))};
}

Point SDLHandler::getPointPositionInScreen(const Point &point, SDL_Rect displayImageRect, Image &originalImage) {
	return {static_cast<int>(point.x * ((double) displayImageRect.w / originalImage.w)),
					static_cast<int>(point.y * ((double) displayImageRect.h / originalImage.h))};
}

void SDLHandler::update() {
	SDL_RenderPresent(renderer);
}

void SDLHandler::setWindowCaption(const std::string &caption) {
	SDL_SetWindowTitle(window, caption.c_str());
}
