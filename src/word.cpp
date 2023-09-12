#include "word.h"

Word::Word(const std::string word) : _word{word} {

}

std::string Word::get() const {
    return _word;
}


#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "doctest/doctest.h"
TEST_CASE("we can have tests written here, to test impl. details")
{
    CHECK(true);
}
#endif
