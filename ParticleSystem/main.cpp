#include "ParticleSystemLauncher.h"
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << PROJECT_NAME << " " << PROJECT_VERSION << std::endl
              << PROJECT_GITHUB << std::endl
              << PROJECT_AUTHOR << std::endl;
    ParticleSystemLauncher app;
    app.start();
    return 0;
}
