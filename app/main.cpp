// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#include "word.h"
#include <cstdio>
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

std::string getHangmanPicture(int lives);

void clearConsole();

int main() {
    Word w = Word{"kubernetes"};
    int lives = 6;

    clearConsole();
    printVersionInfo();
    std::cout << "Press ANY key to Play" << std::endl;
    getchar();
    clearConsole();

    while (lives >= 0) {
        std::cout << getHangmanPicture(lives);
        std::string input;
        std::cout << "Guess a letter: ";
        std::cin >> input;
        bool isCorrectGuess = w.guessLetter(input);
        if (!isCorrectGuess) {
            lives--;
        }
        clearConsole();
    }

    return 0;
}

void clearConsole() {
    // Unix to clear the screen
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

std::string getHangmanPicture(int lives) { 
    auto start = R"(
 Hangman        +-------+
                |      \|
                        |
                        |
                        |
                       /|
            ============|
 )";
    auto hangman1 =R"(
 Hangman        +-------+
                |      \|
                O       |
                        |
                        |
                       /|
            ============|
 )";
    auto hangman2 =R"(
 Hangman        +-------+
                |      \|
                O       |
                |       |
                        |
                       /|
            ============|
 )";
    auto hangman3 = R"(
 Hangman        +-------+
                |      \|
                O       |
               /|       |
                        |
                       /|
            ============|
 )";
    auto hangman4 = R"(
 Hangman        +-------+
                |      \|
                O       |
               /|       |
               /        |
                       /|
            ============|
 )";
    auto hangman5 = R"(
 Hangman        +-------+
                |      \|
                O       |
               /|       |
               / \      |
                       /|
            ============|
 )";
    auto hangman6 = R"(
 Hangman        +-------+
                |      \|
                O       |
               /|\      |
               / \      |
                       /|
            ============|

GAME OVER!
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
