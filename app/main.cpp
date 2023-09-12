// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#include "word.h"
#include <ostream>
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "exampleConfig.h"
#include "example.h"

void printVersionInfo() {
  std::cout << "C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR
            << "."
            << PROJECT_VERSION_MINOR
            << "."
            << PROJECT_VERSION_PATCH
            << "."
            << PROJECT_VERSION_TWEAK
            << std::endl;
  std::system("cat ../LICENSE");
  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  //Dummy d = Dummy();
}

std::string getHangmanPicture(int lives) {
    auto start =
        R"(
Hangman        +-------+
               |      \|
               O       |
                       |
                       |
                      /|
           ============|
)";
    auto hangman1 =
        R"(
Hangman        +-------+
               |      \|
               O       |
                       |
                       |
                      /|
           ============|
)";
    auto hangman2 =
        R"(
Hangman        +-------+
               |      \|
               O       |
               |       |
                       |
                      /|
           ============|
)";
    auto hangman3 =
        R"(
Hangman        +-------+
               |      \|
               O       |
              /|       |
                       |
                      /|
           ============|
)";
    auto hangman4 =
        R"(
Hangman        +-------+
               |      \|
               O       |
              /|       |
              /        |
                      /|
           ============|
)";
    auto hangman5 =
        R"(
Hangman        +-------+
               |      \|
               O       |
              /|       |
              / \      |
                      /|
           ============|
)";
    auto hangman6 =
        R"(
Hangman        +-------+
               |      \|
               O       |
              /|\      |
              / \      |
                      /|
           ============|
)";

    switch (lives) {
        case 6:
            return start;
        case 5:
            return hangman1;
        case 4:
            return hangman2;
        case 3:
            return hangman3;
        case 2:
            return hangman4;
        case 1:
            return hangman5;
        case 0:
            return hangman6;
        default:
            return "";
    }
}

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
    Word w = Word{"kubernetes"};
    std::cout << w.get() << std::endl;
    int lives = 6;
    std::cout << lives << std::endl;
    std::vector<std::string> correctGuesses;

    while (lives >= 0) {
        std::cout << getHangmanPicture(lives);
        std::string input;
        std::cout << "Guess a letter: ";
        std::cin >> input;
        bool isCorrectGuess = w.guessLetter(input);
        if (!isCorrectGuess) {
            lives--;
        }

        // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
        std::cout << "\x1B[2J\x1B[H";
    }

    return 0;
}
