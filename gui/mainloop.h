#ifndef MAINLOOP_H
#define MAINLOOP_H

#include <SDL2/SDL.h>
#include <iostream>

extern "C"

class MainLoop
{
public:
    MainLoop();

    ~MainLoop();

    void run();

    bool init();

    void delaySeconds(int seconds);

    void fillBg(int r, int g, int b);

    void update();

private:
    SDL_Window * m_sdlWindow;
    SDL_Surface * m_sdlSurface;
};

#endif // MAINLOOP_H
