#include "game.h"

/*
TODO:
    1) will never fully close the application.
    2) Doesn't update the renderer;
    3) Not sure if game should include engine or if engine should include the game. Game Engine Architecture gives an example
       of the engine including the Simulation (the game) and running it after all the subsystems
       have been loaded. But not sure if I should take that approach or not.
*/

void Game::init() {
    player.setTexture("images/ball.png");
}

void Game::run() {
    handleInput();
    update();
    render();
}

void Game::handleInput() {
    player.handleInput();

}

void Game::update() {
    player.update();

}

void Game::render() {
    RenderingManager::getInstance().clearRenderer();
    player.render();
    RenderingManager::getInstance().presentToScreen();
}

void Game::destroy() {


}

