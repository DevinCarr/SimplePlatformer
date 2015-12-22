#include "player.h"

Player::Player() {
    texture = nullptr;
}

Player::~Player() {
    if (texture) {
        texture->free();
        /*SDL_DestroyTexture(texture);*/
        delete texture;
        texture = nullptr;
    }
}

void Player::setTexture(std::string path) {
    texture = RenderingManager::getInstance().createTexture(path);
    //texture = renderer->createTexture(path);
}

void Player::handleInput() {

    if(InputManager::getInstance().isHeld(SDLK_LEFT)){
        velocity.x -= 4;
    }
    if(InputManager::getInstance().isHeld(SDLK_RIGHT)){
        velocity.x += 4;
    }
    if(InputManager::getInstance().isHeld(SDLK_UP)){
        velocity.y -= 4;
    }
    if(InputManager::getInstance().isHeld(SDLK_DOWN)){
        velocity.y += 4;
    }

    if(InputManager::getInstance().isReleased(SDLK_LEFT)){
        velocity.x = 0;
    }
    if(InputManager::getInstance().isReleased(SDLK_RIGHT)){
        velocity.x = 0;
    }
    if(InputManager::getInstance().isReleased(SDLK_UP)){
        velocity.y = 0;
    }
    if(InputManager::getInstance().isReleased(SDLK_DOWN)){
        velocity.y = 0;
    }
//
//    SDL_Event e;
//    while(SDL_PollEvent(&e)) {
//        switch(e.type) {
//        std::cout << e.type << std::endl;
//        case SDL_KEYDOWN:
//            switch(e.key.keysym.sym) {
//                case SDLK_LEFT:
//                    velocity.x = -4;
//                    break;
//                case SDLK_RIGHT:
//                    velocity.x = 4;
//                    break;
//                case SDLK_UP:
//                    velocity.y = -4;
//                    break;
//                case SDLK_DOWN:
//                    velocity.y = 4;
//                    break;
//            }
//            break;
//
//        case SDL_KEYUP:
//            switch(e.key.keysym.sym) {
//                case SDLK_LEFT:
//                    velocity.x = 0;
//                    break;
//                case SDLK_RIGHT:
//                    velocity.x = 0;
//                    break;
//                case SDLK_UP:
//                    velocity.y = 0;
//                    break;
//                case SDLK_DOWN:
//                    velocity.y = 0;
//                    break;
//            }
//            break;
//        }
//    }
}

void Player::update() {
    position += velocity;
}

void Player::render() {
    RenderingManager::getInstance().renderTexture(*texture, position.x, position.y);
}
