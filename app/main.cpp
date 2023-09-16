// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#include "game.h"
#include "wordFactory.h"
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include "exampleConfig.h"

void printVersionInfo();

int main() {

    printVersionInfo();
    std::cout << "Press ANY key to Play" << std::endl;
    getchar();

    WordFactory wordFactory{};
    Game game = Game{wordFactory};
    int exitCode = game.start();

    return exitCode;
}

void printVersionInfo() {
    std::cout << "Hangman"
        << PROJECT_VERSION_MAJOR
        << "."
        << PROJECT_VERSION_MINOR
        << "."
        << PROJECT_VERSION_PATCH
        << "."
        << PROJECT_VERSION_TWEAK
        << std::endl;
    std::system("cat ../LICENSE");
}
