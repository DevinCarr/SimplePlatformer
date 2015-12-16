#include "renderingmanager.h"

RenderingManager::RenderingManager() {
    gWindow = nullptr;
    gRenderer = nullptr;

    init();
}

RenderingManager::~RenderingManager() {
}

RenderingManager& RenderingManager::operator=(const RenderingManager& right) {
    gWindow = right.getWindow();
    gRenderer = right.getRenderer();

    return *this;

}
void RenderingManager::init() {

    log.openFile("renderingmanager_log.txt");
    log.writeMessage("Attempting to create window \n");

    gWindow = SDL_CreateWindow("SDL2 Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN);

    if (gWindow) {
        log.writeMessage("successfully created window\n");
        log.writeMessage("attempting to create renderer \n");

        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (gRenderer) {
            log.writeMessage("successfully created renderer\n");

            SDL_SetRenderDrawColor(gRenderer, 0x99, 0x99, 0x99, 0xFF);

            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags)) {
                log.writeMessage("Error initializing SDL image library\n");

            } else {
                log.writeMessage("successfully initialized SDL image library\n");
            }
        } else {
            log.writeMessage("Error creating renderer\n");
        }
    } else {
        log.writeMessage("Error creating window\n");
    }
}

Texture* RenderingManager::createTexture(std::string path) {
    Texture* tempTexture = new Texture();

    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        //TODO: write texture error message to log.

    } else {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL) {
            //TODO: write texture error message to log.
        } else {
            tempTexture->setWidth(loadedSurface->w);
            tempTexture->setHeight(loadedSurface->h);
        }

        SDL_FreeSurface(loadedSurface);
    }

    tempTexture->setTexture(newTexture);

    return tempTexture;
}

void RenderingManager::clearRenderer() {
    SDL_RenderClear(gRenderer);
}

void RenderingManager::renderTexture(Texture& texture, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {

    int width = texture.getWidth();
    int height = texture.getHeight();

    //Set rendering space and render to screen
    SDL_Rect render_quad = { x, y, width, height };

    //Set clip rendering dimensions
    if (clip != NULL) {
        render_quad.w = clip->w;
        render_quad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx(gRenderer, texture.getTexture(), clip, &render_quad, angle, center, flip);
}

void RenderingManager::presentToScreen() {
    SDL_RenderPresent(gRenderer);

}

void RenderingManager::destroy() {
    log.closeFile();
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    gRenderer = nullptr;
    gWindow = nullptr;
}
