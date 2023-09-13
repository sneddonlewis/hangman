#pragma once
#include <iostream>
#include <string>

class Word final {
public:
    Word(const std::string word);

    std::string get() const;
    bool guessLetter(char letter) {
        std::cout << letter << std::endl;
        return false;
    }

private:
    std::string _word;
};

