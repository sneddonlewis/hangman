#include "game.h"
#include "wordFactory.h"
#include "word.h"
#include "game.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdio>
#include <ios>
#include <limits>
#include <ostream>

Game::Game(WordFactory wordFactory) : _wordFactory{wordFactory}, _lives{6} {}

std::string getHangmanPicture(int lives);
Word getWord();
void clearConsole();
char readChar();

int Game::start() {
    bool shouldReplay = loop(_wordFactory.create());
    while (shouldReplay) {
        _lives = 6;
        shouldReplay = loop(_wordFactory.create());
    }   
    return 0;
}

bool Game::loop(Word word) {
    while (_lives >= 0) {
        clearConsole();
        std::cout << getHangmanPicture(_lives);
        std::cout << word.getHidden() << std::endl;
        std::cout << "Guess a letter: ";
        char guess = readChar();
        bool isCorrectGuess = word.guessLetter(guess);
        if (!isCorrectGuess) {
            _lives--;
        }
        if (word.isComplete()) {
            std::cout << "WINNER!" << std::endl;
            std::cout << "Continue \"y\"? or quit \"q\"" << std::endl;
            char continueInput = readChar();
            switch (continueInput) {
                case 'y':
                    std::cout << "Ok" << std::endl;
                    return true;
                case 'q':
                    std::cout << "Bye" << std::endl;
                    return false;
                default:
                    std::cout << "Invalid option" << std::endl;
                    return false;
            }
        }
        if (_lives == 0) {
            std::cout << "GAME OVER!" << std::endl;
            std::cout << "Continue \"y\"? or quit \"q\"" << std::endl;
            char continueInput = readChar();
            switch (continueInput) {
                case 'y':
                    std::cout << "Ok" << std::endl;
                    return true;
                case 'q':
                    std::cout << "Bye" << std::endl;
                    return false;
                default:
                    std::cout << "Invalid option" << std::endl;
                    return false;
            }
        }
    }
    return false;
}

char readChar() {
    char guess;
    std::cin >> guess;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return guess;
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
