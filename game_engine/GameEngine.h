#ifndef BOMBERMAN_GAMEENGINE_H
#define BOMBERMAN_GAMEENGINE_H


#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <time.h>
#include<stdio.h>
#include<stdlib.h>

typedef std::map<int, std::string> PlayerDict;  // Player ID, Action
typedef std::map<int, std::tuple<int, int>> PlayerPosition;  // Player ID, Position (x,y)
typedef std::map<int, int, std::tuple<int, int>> BombState;  // Delay left, Radius, Position (x,y)


class GameEngine {

    public:
        GameEngine();
        GameEngine(int width, int height, int delay, int radius, int maxBombs);
        PlayerDict readFromDispatcher();
        void sendToDispatcher();
        void updateBoard(PlayerDict playersActions);
        void play();

        friend std::ostream& operator<<(std::ostream& out, const GameEngine& m){
            for(int i=0 ; i<(m.width * m.height) ; i++){
                out<<m.board[i]<<" ";
                if(i%(m.height)==m.height -1){
                    out<<std::endl;
                }
            }
        }


    private:
        void executePlayersActions(PlayerDict playersActions);
        void updateBombs();
        void explodeAndKill();
        void generateBoard();
        void instantiatePlayers();
        int turn;
        int width;
        int height;
        bool random;
        int delay;
        int radius;
        int maxBombs;
        int nbrPlayers;
        char* board;
        PlayerPosition players;
        BombState bombs;
};


#endif //BOMBERMAN_GAMEENGINE_H
