#ifndef MAZESOLVER_IMAGE_H
#define MAZESOLVER_IMAGE_H

#include <string>

#include <SDL2/SDL_image.h>

class SDLHandler;

class Image {
	friend class SDLHandler;

public:
	Image(SDL_Renderer *, const std::string &filePath);

	Image(const Image &);

	Image(const Image &&);

	~Image();

	std::tuple<int, int> getSize();

	void loadFromFile(SDL_Renderer *, const std::string &filePath);

private:
	void setSize();

	SDL_Texture *texture = nullptr;
	int w, h;
};

#endif //MAZESOLVER_IMAGE_H
