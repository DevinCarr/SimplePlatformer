#ifndef GAME_H_
#define GAME_H_

#include "player.h"
#include "renderingmanager.h"
#include "inputmanager.h"

class Game: public Singleton<Game> {
public:

    void init();

    void run();

    void handleInput();

    void update();

    void render();

    void destroy();

private:
    bool running = true;
    Player player;

};

#endif
