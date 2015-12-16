#include "texture.h"
Texture::Texture(): mWidth(0), mHeight(0), mTexture(NULL) {
}

Texture::~Texture() {
    free();
}

//bool Texture::load_from_file( std::string path ) {
//    //Get rid of preexisting texture
//    free();
//
//    //The final texture
//    SDL_Texture* new_texture = NULL;
//
//    //Load image at specified path
//    SDL_Surface* loaded_surface = IMG_Load( path.c_str() );
//    if( loaded_surface == NULL ) {
//        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
//    } else {
//        //Color key image
//        SDL_SetColorKey( loaded_surface, SDL_TRUE, SDL_MapRGB( loaded_surface->format, 0, 0xFF, 0xFF ) );
//
//        //Create texture from surface pixels
//        new_texture = SDL_CreateTextureFromSurface( g_renderer, loaded_surface );
//        if( new_texture == NULL ) {
//            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
//        } else {
//            //Get image dimensions
//            mWidth = loaded_surface->w;
//            mHeight = loaded_surface->h;
//        }
//
//        //Get rid of old loaded surface
//        SDL_FreeSurface( loaded_surface );
//    }
//
//    //Return success
//    mTexture = new_texture;
//    return mTexture != NULL;
//}


void Texture::free() {
    //Free texture if it exists
    if( mTexture != NULL ) {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::set_color( unsigned char red, unsigned char green, unsigned char blue ) {
    //Modulate texture rgb
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void Texture::set_blend_mode( SDL_BlendMode blending ) {
    //Set blending function
    SDL_SetTextureBlendMode( mTexture, blending );
}

void Texture::set_alpha( unsigned char alpha ) {
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

//void Texture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip ) {
//    //Set rendering space and render to screen
//    SDL_Rect render_quad = { x, y, mWidth, mHeight };
//
//    //Set clip rendering dimensions
//    if( clip != NULL ) {
//        render_quad.w = clip->w;
//        render_quad.h = clip->h;
//    }
//
//    //Render to screen
//    SDL_RenderCopyEx( g_renderer, mTexture, clip, &render_quad, angle, center, flip );
//}

SDL_Texture* Texture::getTexture() {
    return mTexture;
}

void Texture::setTexture(SDL_Texture* texture) {
    mTexture = texture;
}
int Texture::getWidth() {
    return mWidth;
}

int Texture::getHeight() {
    return mHeight;
}

void Texture::setHeight(int height) {
    mHeight = height;
}

void Texture::setWidth(int width) {
    mWidth = width;
}
