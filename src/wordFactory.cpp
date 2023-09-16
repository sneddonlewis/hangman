#include "wordFactory.h"

WordFactory::WordFactory() {}

Word WordFactory::create() {
    return Word{"kubernetes"};
}
