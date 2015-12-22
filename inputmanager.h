#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "singleton.h"
//#include <map>

#include "SDL2/SDL.h"

class InputManager: public Singleton<InputManager> {
public:

    void init();
    void process(SDL_Event* e);

    void clearReleased();
    void clearHeld();

    bool isHeld(SDL_Keycode);
    bool isReleased(SDL_Keycode);

    void destroy();
private:
    //Keys held on the current frame

    bool heldKeys[512];
    bool releasedKeys[512];
//    std::map<SDL_Keysym, int> heldKeys;
////    //Keys released on the current frame
//    std::map<SDL_Keysym, int> releasedKeys;
};
#endif // INPUTMANAGER_H_
