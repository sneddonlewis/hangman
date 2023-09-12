#include "word.h"

Word::Word() {

}

std::string Word::get() {
    return "kubernetes";
}


#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "doctest/doctest.h"
TEST_CASE("we can have tests written here, to test impl. details")
{
    CHECK(true);
}
#endif
