#include "engine.h"

Engine::Engine() {
    std::cout << "Starting Engine" << std::endl;
    if(init()){
        run();
    }
}

Engine::~Engine() {
//    destroy();
    std::cout << "Destroying Engine" << std::endl;
}

bool Engine::init() {
    bool success = true;

    log.openFile("engine_log.txt");
	
    if(SDL_Init(SDL_INIT_EVENTS|SDL_INIT_VIDEO) >= 0) {
        std::cout << "Initilized SDL2 \n";
        log.writeMessage("Initialized SDL2 \n");
		
		log.writeMessage("Initializing RenderingManager \n");
		
		RenderingManager::getInstance(); 

		//player = new Player();
		player.setTexture("images/ball.png");
   
	} else {
        std::cout << "Error loading SDL" <<std:: endl;
        log.writeMessage("Error initializing SDL2\n");
        success = false;
    }

    return success;
}

bool Engine::loadMedia() {
	
	return true;
}

void Engine::render() {
	RenderingManager::getInstance().clearRenderer();
	player.render();
	RenderingManager::getInstance().presentToScreen();

}
void Engine::run() {
    running = true;
    while(running) {
        SDL_Event e;

        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                running= false;
                destroy();
                break;
            }
        }

		render();
    }
}


void Engine::destroy() {

    //std::cout << "destryoing renderer " << std::endl;
    //SDL_DestroyRenderer(m_gRenderer);
    //std::cout << "destryoing window" << std::endl;
    //SDL_DestroyWindow(m_gWindow);

    log.closeFile();

    //m_gRenderer = nullptr;
    //m_gWindow = nullptr;

    //TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
