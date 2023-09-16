#pragma once
#include "word.h"

class WordFactory final {
public:
    WordFactory();
    Word create();
};
