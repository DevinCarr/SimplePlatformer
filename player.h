#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"

#include "texture.h"
#include "renderingmanager.h"
#include "inputmanager.h"

#include "vector2d.h"

#include "SDL2/SDL.h"

#include "iostream"

class Player : public Entity {
public:
    Player();
    ~Player();
    void setTexture(std::string path);
    virtual void handleInput();
    virtual void update();
    virtual void render();
private:
    Texture *texture;

    Vector2D position;
    Vector2D velocity;

};
#endif //PLAYER_H_
