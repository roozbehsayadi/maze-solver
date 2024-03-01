
#include "SDLHandler.h"

#include <iostream>

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

void SDLHandler::setWindowCaption(const std::string &caption) {
	SDL_SetWindowTitle(window, caption.c_str());
}
