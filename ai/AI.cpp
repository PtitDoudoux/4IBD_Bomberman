#include "AI.h"

AI::AI() {
    std::string::size_type sz;
    std::string gameEngineOutput;
    std::getline(std::cin, gameEngineOutput); // START players
    this->id = std::stoi(gameEngineOutput, &sz);
    std::getline(std::cin, gameEngineOutput); // STOP players
    std::getline(std::cin, gameEngineOutput); // START settings
    while (gameEngineOutput != "STOP settings") {
        std::getline(std::cin, gameEngineOutput);
        this->config[gameEngineOutput.substr(0, gameEngineOutput.find(' '))] = gameEngineOutput.substr(1, gameEngineOutput.find(' '));
    }
}

void AI::play() {
    std::srand(std::time(NULL));
    int width, height, i, action, turn;
    std::string::size_type sz;
    std::string gameEngineOutput;
    while (gameEngineOutput != "END GAME") {
        std::getline(std::cin, gameEngineOutput); // START turn X
        turn = std::stoi(gameEngineOutput, &sz);
        std::getline(std::cin, gameEngineOutput);  // Getting Width height
        width = std::stoi(gameEngineOutput.substr(0, gameEngineOutput.find('*')), &sz);
        height = std::stoi(gameEngineOutput.substr(1, gameEngineOutput.find('*')), &sz);
        for (i=0; i < height; i++) std::getline(std::cin, gameEngineOutput); // Read array
        action = std::rand() % 6;
        if (action == 0) {
            std::cout << "action" << turn;
            std::cout  << 'U';
        }
        if (action == 1) {
            std::cout << "action" << turn;
            std::cout  << 'D';
        }
        if (action == 2) {
            std::cout << "action" << turn;
            std::cout  << 'L';
        }
        if (action == 3) {
            std::cout << "action" << turn;
            std::cout  << 'R';
        }
        if (action == 4) {
            std::cout << "action" << turn;
            std::cout  << 'B';
        }
        if (action == 5) {
            std::cout << "action" << turn;
            std::cout  << "NOACTION";
        }

    }
}
