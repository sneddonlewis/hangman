#include "engine.h"
#include "wordFactory.h"

Engine::Engine(WordFactory wordFactory) : _wordFactory{wordFactory} {}

int Engine::start() {
    auto game = Game{_wordFactory.create()};
    bool shouldReplay = game.loop();
    while (shouldReplay) {
        auto mainGame = Game{_wordFactory.create()};
        shouldReplay = mainGame.loop();
    }   
    return 0;
}
