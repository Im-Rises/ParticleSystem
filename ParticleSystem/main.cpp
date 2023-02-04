#include "ParticleSystemLauncher.h"
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << PROJECT_NAME << " " << PROJECT_VERSION << std::endl;
    std::cout << PROJECT_GITHUB << std::endl;
    std::cout << PROJECT_AUTHOR << std::endl;
    ParticleSystemLauncher app;
    app.start();
    return 0;
}
