#ifndef ENGINE_H_
#define ENGINE_H_

#include <iostream>
#include <string>

#include "singleton.h"
#include "texture.h"

#include "SDL2/SDL.h"

#include "game.h"

#include "renderingmanager.h"
#include "logger.h"

class Engine : public Singleton<Engine> {
public:
    Engine();
    ~Engine();

    bool init();

    void run();

    bool loadMedia();

    void destroy();

protected:
    bool running;

    Log log;
};
#endif // ENGINE_H_
