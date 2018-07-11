#include <iostream>
#include "game_engine/GameEngine.h"
#include "ai/AI.h"

int main(int argc, char *argv[]) {
    if (argv[0] == "ia") {
        AI ai = AI();
        ai.play();
    }
    if (argv[0] == "game_engine") {
        GameEngine ge = GameEngine();
    }
    // std::cout<<GameEngine();
}