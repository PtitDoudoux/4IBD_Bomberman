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
        static void play2();

    private:
        int id;
        std::map<std::string, std::string> config;
        // int &position;
};


#endif //BOMBERMAN_AI_H
