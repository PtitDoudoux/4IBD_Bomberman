#ifndef BOMBERMAN_GAMEENGINE_H
#define BOMBERMAN_GAMEENGINE_H

#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

typedef map<int, string> PlayerDict;  // Player ID, Action
typedef map<int, tuple<int, int>> PlayerPosition;  // Player ID, Position (x,y)
typedef vector<struct bomb> BombList;

struct bomb {
  int delay;
  int radius;
  int pos;
};

class GameEngine {

    public:
        GameEngine();
        GameEngine(int width, int height, int delay, int radius, int maxBombs);
        PlayerDict readFromDispatcher();
        void sendToDispatcher();
        void updateBoard(PlayerDict playersActions);
        void play();


    private:
        void executePlayersActions(PlayerDict playersActions);
        void updateBombs();
        void explodeAndKill();
        void generateBoard();
        void instantiatePlayers();
	int* getCoordinate(int pos);
	void killPlayer(int playerId);
	vector<int> getDeathCell(int x, int y);
        int turn;
        int width;
        int height;
        int delay;
        int radius;
        int maxBombs;
        int* board;
        PlayerPosition players;
	PlayerDict playerDict;
        BombList bombList;
};


#endif //BOMBERMAN_GAMEENGINE_H
