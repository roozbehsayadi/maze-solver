
#include "image.h"

#include <tuple>
#include <iostream>

#include "exceptions/sdl_exception.h"

Image::Image(SDL_Renderer *renderer, const std::string &filePath) {
	loadFromFile(renderer, filePath);
}

Image::~Image() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
}

std::tuple<int, int> Image::getSize() {
	return {w, h};
}

void Image::loadFromFile(SDL_Renderer *renderer, const std::string &filePath) {
	if (texture) {
		SDL_DestroyTexture(texture);
	}

	texture = IMG_LoadTexture(renderer, filePath.c_str());
	if (!texture) {
		throw SDLException(IMG_GetError());
	}

	setSize();
}

void Image::setSize() {
	SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
}
