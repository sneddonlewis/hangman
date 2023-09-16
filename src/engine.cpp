#include "engine.h"
#include "wordFactory.h"

Engine::Engine(WordFactory wordFactory) : _wordFactory{wordFactory} {}

int Engine::start() {
    auto game = Game{_wordFactory.create()};
    bool shouldReplay = game.loop();
    while (shouldReplay) {
        auto game = Game{_wordFactory.create()};
        shouldReplay = game.loop();
    }   
    return 0;
}
