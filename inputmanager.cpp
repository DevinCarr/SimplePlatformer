#include "inputmanager.h"


void InputManager::init() {
    clearHeld();
    clearReleased();
}

void InputManager::process(SDL_Event* e) {
    switch(e->type) {
    case  SDL_KEYDOWN:
        heldKeys[e->key.keysym.sym] = true;
        break;
    case SDL_KEYUP:
        releasedKeys[e->key.keysym.sym] = true;
        heldKeys[e->key.keysym.sym] = false;
        break;
    }
}

void InputManager::clearReleased() {
    for(int i = 0; i < 512; i++) {
        releasedKeys[i] = false;
    }
}

void InputManager::clearHeld() {
    for(int i = 0; i < 512; i++) {
        heldKeys[i] = false;
    }
}

bool InputManager::isHeld(SDL_Keycode key) {
    return heldKeys[key];
}

bool InputManager::isReleased(SDL_Keycode key) {
    return releasedKeys[key];
}

void InputManager::destroy() {
    clearHeld();
    clearReleased();
}
