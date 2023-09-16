#pragma once
#include "wordFactory.h"
#include "game.h"

class Engine final {
public:
    Engine(WordFactory wordFactory);
    int start();
private:
    WordFactory _wordFactory;
};
