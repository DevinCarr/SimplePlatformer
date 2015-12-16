#include "engine.h"
#include "player.h"
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
