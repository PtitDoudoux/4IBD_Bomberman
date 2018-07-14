#ifndef BOMBERMAN_AI_H
#define BOMBERMAN_AI_H


#include <string>
#include <iostream>
#include <map>
#include <ctime>


class AI {
    public:
        AI();
        void play();

    private:
        int id;
        std::map<std::string, std::string> config;
        // int &position;  TODO: Handle it
};


void ai_play();


#endif //BOMBERMAN_AI_H
