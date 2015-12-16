#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Texture {
public:
    //Initializes variables
    Texture();

    //Deallocates memory
    ~Texture();

    //Loads image at specified path
    //bool load_from_file( std::string path );

    //Deallocates texture
    void free();

    //Set color modulation
    void set_color( unsigned char red, unsigned char green, unsigned char blue );

    //Set blending
    void set_blend_mode( SDL_BlendMode blending );

    //Set alpha modulation
    void set_alpha( unsigned char alpha );

	void setTexture(SDL_Texture* texture);
    //Renders texture at given point
    //void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    SDL_Texture* getTexture();
    //Gets image dimensions
    int getWidth();
    int getHeight();

	void setHeight(int height);
	void setWidth(int width);

private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    //Image dimensions
    int mWidth;
    int mHeight;
};

#endif // TEXTURE_H
