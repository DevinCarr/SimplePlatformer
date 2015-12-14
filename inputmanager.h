#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <map>

class InputManager: public Singleton<InputManager> {
public:

    void process(SDL_Event*);

    bool isHeld(SDL_Keysym);

private:
    std::map<SDL_Keysym, bool> heldKeys;
    std::map<SDL_keysym, bool> releasedKeys;
};
#endif // INPUTMANAGER_H_
