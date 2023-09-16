#pragma once
#include "word.h"
#include "wordFactory.h"

class Game final {
public:
    Game(Word word);
    bool loop();
private:
    Word _word;
    int _lives;
};
