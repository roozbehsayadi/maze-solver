
#include "SDLHandler.h"

const auto windowName = "window";

int main() {
	SDLHandler::getInstance().setWindowCaption(windowName);

	return 0;
}
