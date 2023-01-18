#include "mainloop.h"


MainLoop::MainLoop()
{
    m_sdlWindow = nullptr;
}

MainLoop::~MainLoop()
{
    // SDL_VideoQuit();
    // SDL_Quit();

    delete m_sdlSurface;
    delete m_sdlWindow;
}

void MainLoop::run()
{
    if (init())
    {

    }

    else
    {
        std::cout << "App exitting!" << std::endl;
    }
}

bool MainLoop::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL init failed: %s\n" << SDL_GetError() << std::endl;
        return false;
    }

    printf("initialized SDL\n");

    m_sdlWindow = SDL_CreateWindow("SDL Example", /* Title of the SDL window */
                                   SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
                                   SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
                                   1280, /* Width of the window in pixels */
                                   720, /* Height of the window in pixels */
                                   0); /* Additional flag(s) */
    m_sdlSurface = new SDL_Surface();

    if(m_sdlWindow == NULL) {
        printf("window could not be created: %s\n", SDL_GetError());
        return false;
    }

    printf("created window\n");

    m_sdlSurface = SDL_GetWindowSurface(m_sdlWindow);

    printf("got window surface\n");

    // make background black
    fillBg(0x00, 0x00, 0x00);

    return true;
}

void MainLoop::delaySeconds(int seconds)
{
    SDL_Delay(seconds*1000);
}

void MainLoop::fillBg(int r, int g, int b)
{
    SDL_FillRect(m_sdlSurface, NULL, SDL_MapRGBA(m_sdlSurface->format, b, g, r, 0xFF));
}

void MainLoop::update()
{
    SDL_UpdateWindowSurface(m_sdlWindow);
}
