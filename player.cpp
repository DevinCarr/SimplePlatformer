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


}

void Player::update() {


}

void Player::render() {
    RenderingManager::getInstance().renderTexture(*texture, 0, 0);
}
