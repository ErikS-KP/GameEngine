#define SDL_MAIN_HANDLED

#include <iostream>
#include "application.h"

int main(int argc, char* argv[]) {
    Application Application;
    Application.run();

    return 0;
}