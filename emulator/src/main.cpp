#include "Application.h"

int SDL_main(int argc, char *argv[])
{
    Application app = Application();

    app.initialise();

    if (!app.isInitialised())
    {
        return -1;
    }

    app.run();

    return 0;
}