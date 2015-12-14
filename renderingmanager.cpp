#include "renderingmanager.h"

RenderingManager::RenderingManager() {
	gWindow = nullptr;
	gRenderer = nullptr;

	init();
}

RenderingManager::~RenderingManager() {
	destroy();
}

RenderingManager& RenderingManager::operator=(const RenderingManager& right) {
	gWindow = right.getWindow();
	gRenderer = right.getRenderer();

	return *this;

}
void RenderingManager::init() {
	bool success = true;
	log.openFile("renderingmanager_log.txt");
	gWindow = SDL_CreateWindow("SDL2 Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN);
	log.writeMessage("Attempting to create window \n");
	if (gWindow) {
		std::cout << "Created Window\n";
		log.writeMessage("successfully created window\n");
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		log.writeMessage("attempting to create renderer \n");
		if (gRenderer) {
			std::cout << "created renderer\n";
			log.writeMessage("successfully created renderer\n");
			SDL_SetRenderDrawColor(gRenderer, 0x99, 0x99, 0x99, 0xFF);

			int imgFlags = IMG_INIT_PNG;

			if (!(IMG_Init(imgFlags) & imgFlags)) {
				log.writeMessage("Error initializing SDL image library\n");
				success = false;
			}
			else {
				std::cout << "initialized img\n";
				log.writeMessage("successfully initialized SDL image library\n");
			}
		}
		else {
			std::cout << "Error loading renderer" << std::endl;
			log.writeMessage("Error creating renderer\n");
			success = false;
		}
	} else {
		std::cout << "Error loading window" << std::endl;
		log.writeMessage("Error creating window\n");
		success = false;
	}
}

Texture* RenderingManager::createTexture(std::string path) {
	Texture* tempTexture = new Texture();

	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		//printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else {
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL) {
			//printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else {
			//Get image dimensions
			tempTexture->setWidth(loadedSurface->w);
			tempTexture->setHeight(loadedSurface->h);
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
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