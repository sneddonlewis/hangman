#include "word.h"

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
    return isCorrect;
}

#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "doctest/doctest.h"
TEST_CASE("we can have tests written here, to test impl. details")
{
    CHECK(true);
}
#endif
