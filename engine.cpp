#include "engine.h"

Engine::Engine() {
    std::cout << "Starting Engine" << std::endl;
    if(init()) {
        run();
    }
}

Engine::~Engine() {
    std::cout << "Destroying Engine" << std::endl;
}

bool Engine::init() {
    bool success = true;

    log.openFile("engine_log.txt");

    if(SDL_Init(SDL_INIT_EVENTS|SDL_INIT_VIDEO) >= 0) {
        log.writeMessage("Initialized SDL2 \n");

        log.writeMessage("Initializing RenderingManager \n");

        RenderingManager::getInstance().init();

        log.writeMessage("Initializing InputManager\n");
        InputManager::getInstance().init();

        log.writeMessage("Initializing Game\n");
        Game::getInstance().init();

    } else {
        log.writeMessage("Error initializing SDL2\n", 2);
        success = false;
    }

    return success;
}

bool Engine::loadMedia() {
    return true;
}

void Engine::run() {
    running = true;
    while(running) {
        SDL_Event e;

        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                running= false;
                destroy();
                break;
            } else {
                InputManager::getInstance().process(&e);
            }
//            Game::getInstance().handleInput();
        }
        Game::getInstance().run();
    }
}


void Engine::destroy() {
    RenderingManager::getInstance().destroy();
    log.closeFile();

    IMG_Quit();
    SDL_Quit();
}
