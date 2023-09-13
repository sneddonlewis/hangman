#include "word.h"
#include <algorithm>
#include <cstddef>

Word::Word(const std::string word) : _word{word}, _hidden(word.length(), '_')
{}

std::string Word::get() const {
    return _word;
}

std::string Word::getHidden() {
    return _hidden;
}

bool Word::guessLetter(char letter) {
    bool isCorrect = _word.find(letter) != std::string::npos;

    if(isCorrect) {
        for(size_t i = 0; i < _word.length(); ++i) {
            if (_word[i] == letter) {
                _hidden[i] = letter;
            }
        }
    }

    return isCorrect;
}

bool Word::isComplete() {
    return _hidden.find('_') == std::string::npos;
}

#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "doctest/doctest.h"
TEST_CASE("we can have tests written here, to test impl. details")
{
    CHECK(true);
}
#endif
