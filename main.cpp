#include <iostream>
#include "game_engine/GameEngine.h"
#include "ai/AI.h"


int main(int argc, char *argv[]) {
    if (std::string(argv[1]) == "ai") {
        // AI ai = AI();
        // ai.play();
        ai_play();
    }
    if (std::string(argv[1]) == "game_engine") {
        GameEngine ge = GameEngine();
        // std::cout << ge;
    }
}
