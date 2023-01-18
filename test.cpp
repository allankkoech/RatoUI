#include <iostream>

#include "gui/mainloop.h"

int main(int argc, char *argv[])
{
    MainLoop mainApp;
    mainApp.run();

    mainApp.delaySeconds(10);

    return 0;
}
