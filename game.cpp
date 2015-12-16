#include "game.h"

/*
TODO:
    1) will never fully close the application.
    2) Doesn't update the renderer;
    3) Not sure if game should include engine or if engine should include the game. Game Engine Architecture gives an example
       of the engine including the Simulation (the game) and running it after all the subsystems
       have been loaded. But not sure if I should take that approach or not.
*/

void Game::init()
{
    Engine::getInstance();

    player.setTexture("images/ball.png");

    run();

}

void Game::run()
{
    //TODO: Have engine track running state
    while(running) {
        SDL_Event e;

        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                running= false;
                destroy();
                break;
            }
        }
        render();
    }
}

void Game::handleInput()
{

}
void Game::update()
{

}
void Game::render()
{
    RenderingManager::getInstance().clearRenderer();
    player.render();
    RenderingManager::getInstance().presentToScreen();
}

void Game::destroy()
{
    Engine::getInstance().destroy();

}

