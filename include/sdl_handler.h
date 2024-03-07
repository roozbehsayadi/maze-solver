#ifndef MAZESOLVER_SDL_HANDLER_H
#define MAZESOLVER_SDL_HANDLER_H

#include <string>
#include <tuple>

#include "SDL2/SDL.h"

#include "image.h"
#include "point.h"

class SDLHandler {
public:
	static SDLHandler &getInstance();

	SDLHandler();

	~SDLHandler();

	Image loadImage(const std::string &);

	void showImage(Image &);

	SDL_Rect showImageKeepRatio(Image &);

	Point getClickPositionInImage(const Point &, SDL_Rect, Image &);

	void update();

	void setWindowCaption(const std::string &);

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
};


#endif //MAZESOLVER_SDL_HANDLER_H
