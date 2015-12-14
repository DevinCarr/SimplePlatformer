#ifndef ENGINE_H_
#define ENGINE_H_

#include <iostream>
#include <string>

#include "singleton.h"
#include "texture.h"

#include "SDL.h"

#include "renderingmanager.h"
#include "logger.h"

#include "player.h"
class Engine : public Singleton<Engine> {
public:
	Engine();
	~Engine();

	bool init();

	void run();

	bool loadMedia();

	void handleInput();
	void update();
	void render();

	void destroy();

protected:
	bool running;

	Player player;

	Log log;
};
#endif // ENGINE_H_
