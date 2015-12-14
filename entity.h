#pragma once
#ifndef ENTITY_H_
#define ENTITY_H_

#include "vector2d.h"

class Entity {
public:
	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
private:
	Vector2D mPosition;
	Vector2D mVelocity;
};

#endif //ENTITY_H_