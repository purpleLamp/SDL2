#include <SDL.h>
#include <stdio.h>

int init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) //0 MEANS OK!
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow(
        NULL,                   //TITLE
        SDL_WINDOWPOS_CENTERED, //X POS
        SDL_WINDOWPOS_CENTERED, //Y POS
        800,                    //WINDOW_WIDTH,
        600,                    //WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS   //decorations,style,constants etc...
    );

    if (!window)
    {
        printf("SDL could not create window! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, 0); //window attached too, default display stuff, special charateristics about this renderer
    if (!renderer)
    {
        printf("SDL could not create renderer! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}
