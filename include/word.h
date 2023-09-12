#pragma once
#include <string>

/**
 * This is a dummy class to demonstrate features of the boiler plate.
 */
class Word {
public:
    Word(const std::string word);

    std::string get();

private:
    std::string _word;
};

