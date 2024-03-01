#ifndef MAZESOLVER_SDLHANDLER_H
#define MAZESOLVER_SDLHANDLER_H

#include <string>

#include "SDL2/SDL.h"

class SDLHandler {
public:
	static SDLHandler &getInstance();

	SDLHandler();

	void setWindowCaption(const std::string &);

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
};


#endif //MAZESOLVER_SDLHANDLER_H
