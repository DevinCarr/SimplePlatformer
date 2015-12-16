#ifndef PLAYER_H_
#define PLAYER_H_
#include "entity.h"

#include "texture.h"

#include "renderingmanager.h"

class Player : public Entity {
public:
    Player();
    ~Player();
    void setTexture(std::string path);
    virtual void handleInput();
    virtual void update();
    virtual void render();
private:
    //Engine *engine;
    Texture *texture;

};
#endif //PLAYER_H_
