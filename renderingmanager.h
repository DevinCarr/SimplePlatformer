#ifndef RENDERINGMANAGER_H_
#define RENDERINGMANAGER_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "logger.h"

#include <string>

#include "singleton.h"
#include "texture.h"

class RenderingManager : public Singleton<RenderingManager> {
public:
    RenderingManager();
    ~RenderingManager();


    RenderingManager& operator=(const RenderingManager&);

    void init();

    SDL_Renderer* getRenderer() const {
        return gRenderer;
    }
    SDL_Window* getWindow() const {
        return gWindow;
    }

    Texture* createTexture(std::string path);

    void clearRenderer();
    void renderTexture(Texture& texture, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void presentToScreen();

    void destroy();

private:
    SDL_Window* gWindow = nullptr;
    SDL_Renderer* gRenderer = nullptr;

    Log log;
};

#endif
