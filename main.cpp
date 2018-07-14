#include <iostream>
#include "game_engine/GameEngine.h"
#include "ai/AI.h"

int main(int argc, char *argv[]) {
    // for (int i=0; i < argc; i++) std::cout << i << ":" << argv[i] << std::endl;
    if (std::string(argv[1]) == "ai") {
        // AI ai = AI();
        // ai.play();
        AI::play2();
    }
    if (std::string(argv[1]) == "game_engine") {
        GameEngine ge = GameEngine();
    }
    // std::cout<<GameEngine();
}