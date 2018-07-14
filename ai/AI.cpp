#include "AI.h"

AI::AI() {
    std::string::size_type sz;
    std::string gameEngineOutput;
    while (gameEngineOutput != "START players") std::cin >> gameEngineOutput;
    // std::cin >> gameEngineOutput;  // std::getline(std::cin, gameEngineOutput); // START players
    std::cin >> gameEngineOutput;  // Player ID
    this->id = std::stoi(gameEngineOutput, &sz);
    std::cin >> gameEngineOutput;  // std::getline(std::cin, gameEngineOutput); // STOP players
    std::cin >> gameEngineOutput;  // std::getline(std::cin, gameEngineOutput); // START settings
    while (true) {
        std::cin >> gameEngineOutput;  // std::getline(std::cin, gameEngineOutput);
        if (gameEngineOutput == "STOP settings") break;
        this->config[gameEngineOutput.substr(0, gameEngineOutput.find(' '))] = gameEngineOutput.substr(1, gameEngineOutput.find(' '));
    }
}

void AI::play() {
    std::srand(std::time(NULL));
    int width, height, i, action, turn;
    std::string::size_type sz;
    std::string gameEngineOutput;
    while (true) {
        std::cin >> gameEngineOutput;  // std::getline(std::cin, gameEngineOutput); // START turn X
        turn = std::stoi(gameEngineOutput, &sz);
        // std::cin >> gameEngineOutput;  // std::getline(std::cin, gameEngineOutput);  // Getting Width height
        // width = std::stoi(gameEngineOutput.substr(0, gameEngineOutput.find(' ')), &sz);
        //height = std::stoi(gameEngineOutput.substr(1, gameEngineOutput.find(' ')), &sz);
        // for (i=0; i < height; i++) std::cin >> gameEngineOutput;  // std::getline(std::cin, gameEngineOutput); // Read array, Skipping it
        // std::cin >> gameEngineOutput;  // std::getline(std::cin, gameEngineOutput); // STOP turn X
        while (gameEngineOutput.find("STOP turn") != std::string::npos) std::cin >> gameEngineOutput;
        // action = std::rand() % 5;
        action = 3;
        if (action == 0) {
            // std::cout << "START actions " << turn << " U";
            std::cout << "START actions " << turn << std::endl;
            std::cout << 'U' << std::endl;
            std::cout << "STOP actions" << std::endl;
        }
        if (action == 1) {
            // std::cout << "START actions " << turn << " D";
            std::cout << "START actions " << turn << std::endl;
            std::cout << 'U' << std::endl;
            std::cout << "STOP actions" << std::endl;
        }
        if (action == 2) {
            // std::cout << "START actions " << turn << " L";
            std::cout << "START actions " << turn << std::endl;
            std::cout << 'L' << std::endl;
            std::cout << "STOP actions" << std::endl;
        }
        if (action == 3) {
            // std::cout << "START actions " << turn << " R";
            std::cout << "START actions " << turn << std::endl;
            std::cout << 'R' << std::endl;
            std::cout << "STOP actions" << std::endl;
        }
        if (action == 4) {
            // std::cout << "START actions " << turn << " B";
            std::cout << "START actions " << turn << std::endl;
            std::cout << 'B' << std::endl;
            std::cout << "STOP actions" << std::endl;
        }
        if (action == 5) {
            // std::cout << "START actions " << turn << " NOACTION";
            std::cout << "START actions " << turn << std::endl;
            std::cout << "NOACTION" << std::endl;
            std::cout << "STOP actions" << std::endl;
        }
    }
}


void AI::play2() {
    std::srand(std::time(NULL));
    bool debug = false;
    int width, height, i, action, id, turn=1;
    std::map<std::string, std::string> config;
    std::string::size_type sz;
    std::string gameEngineOutput;
    if (debug) std::cout << "Before START players" << std::endl;
    while (gameEngineOutput != "START player") std::getline(std::cin, gameEngineOutput);
    if (debug) std::cout << "Getting player ID" << std::endl;
    std::cin >> gameEngineOutput;  // Player ID
    id = std::stoi(gameEngineOutput, &sz);
    if (debug) std::cout << "Before STOP players" << std::endl;
    std::getline(std::cin, gameEngineOutput); // STOP player
    if (debug) std::cout << "Before START settings" << std::endl;
    std::getline(std::cin, gameEngineOutput); // START settings
    while (true) {
        std::getline(std::cin, gameEngineOutput);
        if (gameEngineOutput == "STOP settings") break;
        config[gameEngineOutput.substr(0, gameEngineOutput.find(' '))] = gameEngineOutput.substr(1, gameEngineOutput.find(' '));
    }
    if (debug) std::cout << "Before START turn" << std::endl;
    while (true) {
        std::getline(std::cin, gameEngineOutput); // START turn X
        // turn = std::stoi(gameEngineOutput.substr(2, gameEngineOutput.find(' ')), &sz);
        // turn = std::stoi(gameEngineOutput, &sz);
        // std::cin >> gameEngineOutput;  // std::getline(std::cin, gameEngineOutput);  // Getting Width height
        // width = std::stoi(gameEngineOutput.substr(0, gameEngineOutput.find(' ')), &sz);
        //height = std::stoi(gameEngineOutput.substr(1, gameEngineOutput.find(' ')), &sz);
        // for (i=0; i < height; i++) std::cin >> gameEngineOutput;  // std::getline(std::cin, gameEngineOutput); // Read array, Skipping it
        // std::cin >> gameEngineOutput;  // std::getline(std::cin, gameEngineOutput); // STOP turn X
        while (gameEngineOutput.find("STOP turn") != std::string::npos) std::getline(std::cin, gameEngineOutput);
        action = std::rand() % 5;
        // action = 3;
        if (action == 0) {
            // std::cout << "START action " << turn << " U";
            std::cout << "START action " << turn << std::endl;
            std::cout << 'U' << std::endl;
            std::cout << "STOP action" << std::endl;
        }
        if (action == 1) {
            // std::cout << "START action " << turn << " D";
            std::cout << "START action " << turn << std::endl;
            std::cout << 'U' << std::endl;
            std::cout << "STOP action" << std::endl;
        }
        if (action == 2) {
            // std::cout << "START action " << turn << " L";
            std::cout << "START action " << turn << std::endl;
            std::cout << 'L' << std::endl;
            std::cout << "STOP action" << std::endl;
        }
        if (action == 3) {
            // std::cout << "START action " << turn << " R";
            std::cout << "START action " << turn << std::endl;
            std::cout << 'R' << std::endl;
            std::cout << "STOP action" << std::endl;
        }
        if (action == 4) {
            // std::cout << "START action " << turn << " B";
            std::cout << "START action " << turn << std::endl;
            std::cout << 'B' << std::endl;
            std::cout << "STOP action" << std::endl;
        }
        if (action == 5) {
            // std::cout << "START action " << turn << " NOACTION";
            std::cout << "START actions " << turn << std::endl;
            std::cout << "NOACTION" << std::endl;
            std::cout << "STOP action" << std::endl;
        }
        turn++;
    }
}