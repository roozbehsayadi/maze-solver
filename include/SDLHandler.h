#ifndef MAZESOLVER_SDLHANDLER_H
#define MAZESOLVER_SDLHANDLER_H

#include <string>

#include "SDL2/SDL.h"

#include "image.h"

class SDLHandler {
public:
	static SDLHandler &getInstance();

	SDLHandler();

	~SDLHandler();

	Image loadImage(const std::string &);

	void showImage(Image &);

	void showImageKeepRatio(Image &);

	void update();

	void setWindowCaption(const std::string &);

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
};


#endif //MAZESOLVER_SDLHANDLER_H
