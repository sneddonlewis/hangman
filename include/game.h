#pragma once
#include "word.h"
#include "wordFactory.h"

class Game final {
public:
    Game(WordFactory wordFactory);
    int start();
private:
    bool loop(Word word);
    WordFactory _wordFactory;
    int _lives;
};
