#pragma once
#include <iostream>
#include <string>

class Word final {
public:
    Word(const std::string word);

    std::string get() const;
    std::string getHidden();
    bool guessLetter(char letter);

private:
    std::string _word;
    std::string _hidden;
};

