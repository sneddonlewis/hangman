#pragma once
#include <string>

/**
 * This is a dummy class to demonstrate features of the boiler plate.
 */
class Word {
	public:

  /**
   * Default constructor for Dummy (does nothing).
   */
  Word();

  std::string get() {
      return "kubernetes";
  };
};


#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "doctest/doctest.h"
TEST_CASE("we can have tests in headers if we want")
{
    Word w;
    CHECK("kubernetes" == w.get()); 
}
#endif
