#include "GameEngine.h"

/**
 * Default constructor
 */
GameEngine::GameEngine() {
    this->width = 20;
    this->height= 20;
    this->random = false;
    this->delay = 6;
    this->radius = 5;
    this->maxBombs = 10;
    this->nbrPlayers = 4;
    this->generateBoard();
    this->instantiatePlayers();
}

/**
 * Game Engine constructor for building the game
 * @param width The width of the board
 * @param height the height of the board
 * @param delay The delay by a bomb explode
 * @param radius The radius of the bomb explosion
 * @param maxBombs The maximum number of bomb on the board
 */
GameEngine::GameEngine(int width, int height, int delay, int radius, int maxBombs)
        : width(width), height(height), delay(delay), radius(radius), maxBombs(maxBombs) {
    this->generateBoard();
    this->instantiatePlayers();
}


/**
 * Generate The board of the game
 */
void GameEngine::generateBoard() {
    this->board = new char[this->height * this->width];
    srand(time(NULL));
    if(random==false) {
        for (int r = 0; r < this->height; r++) {
            for (int c = 0; c < this->width; c++) {
                if ((r == 0 || r == this->height - 1) || (c == 0 || c == this->width - 1) || (c % 2 == 0 && r % 2 == 0)) {
                    board[r * this->width + c] = '#';
                } else {
                    board[r * this->width + c] = '_';
                }
            }
        }
    }

    else{
        for (int r = 0; r < this->height; r++) {
            for (int c = 0; c < this->width; c++) {
                if ((r == 0 || r == this->height - 1) || (c == 0 || c == this->width - 1)) {
                    board[r * this->width + c] = '#';
                } else {
                    if (board[r * this->width + c - 1] == '_' && board[r * this->width + c - this->width] == '_' &&  board[r * this->width + c - this->width - 1] == '_' && board[r * this->width + c - this->width + 1] == '_' && (rand() % 4 )> 0) {
                        board[r * this->width + c] = '#';
                    }

                    else {
                        board[r * this->width + c] = '_';
                    }
                }


            }
        }
    }
}

/**
 * Instantiate the players with their position
 */
void GameEngine::instantiatePlayers() {
    for(int i=1; i<=this->nbrPlayers ; i++){
        int x = rand() % this->height;
        int y = rand() % this->width;
        int pos = x*this->width+y;
        char c= board[pos];
        while (c != '_'){
            pos++;
            c=board[pos];
            if(pos=this->height * this->width){
                pos = 0;
            }
        }
        board[pos] = (i+'0');
    }
}


/**
 * Update the board according to the the players information received
 *
 * @param playersActions A dictionnary of PlayerID, Action to execute
 */
void GameEngine::updateBoard(PlayerDict playersActions) {
    this->executePlayersActions(std::move(playersActions));
    this->updateBombs();
    this->explodeAndKill();
}

/**
 * Execute the players based on the information sent by the players
 *
 * @param playersActions A dictionnary of PlayerID, Action to execute
 */
void GameEngine::executePlayersActions(PlayerDict playersActions) {
    for(int i=1; i<=this->nbrPlayers ; i++){
        for (int r = 0; r < this->height*this->width; r++) {
//pas de bombe sous le joueur
            if(board[r] == (i + '0')) {
                if (PlayerDict[i] == 'U') {
                    if (board[r - this->width] == '_') {
                        board[r - this->width] = (i + '0');
                        board[r] = '_';
                    }
                }
                if (PlayerDict[i] == 'D') {
                    if (board[r + this->width] == '_') {
                        board[r + this->width] = (i + '0');
                        board[r] = '_';
                    }
                }
                if (PlayerDict[i] == 'L') {
                    if (board[r - 1] == '_') {
                        board[r - 1] = (i + '0');
                        board[r] = '_';
                    }
                }
                if (PlayerDict[i] == 'R') {
                    if (board[r - this->width] == '_') {
                        board[r - this->width] = (i + '0');
                        board[r] = '_';
                    }
                }
            }

//bombe sous le joueur
            if(board[r] == ((i+4) + '0')) {
                if (PlayerDict[i] == 'U') {
                    if (board[r - this->width] == '_') {
                        board[r - this->width] = (i + '0');
                        board[r] = 'o';
                    }
                }
                if (PlayerDict[i] == 'D') {
                    if (board[r + this->width] == '_') {
                        board[r + this->width] = (i + '0');
                        board[r] = 'o';
                    }
                }
                if (PlayerDict[i] == 'L') {
                    if (board[r - 1] == '_') {
                        board[r - 1] = (i + '0');
                        board[r] = 'o';
                    }
                }
                if (PlayerDict[i] == 'R') {
                    if (board[r - this->width] == '_') {
                        board[r - this->width] = (i + '0');
                        board[r] = 'o';
                    }
                }
            }

//pose une bombe
                if (PlayerDict[i] == 'B') {
                    board[r] = ((i+4) + '0');
                    }
                }
            }

        }
    }

/**
 * Update all the bombs state in the board
 */
void GameEngine::updateBombs() {}

/**
 * Explode the bomb with no timer left and kill the player in the radius
 */
void GameEngine::explodeAndKill() {}

/**
 * Sent to STDOUT the information about the GameEngine
 */
void GameEngine::sendToDispatcher() {}

/**
 * Get the informations by the players from STDOUT sent by the dispatcher
 *
 * @return A dictionnary of PlayerID, Action
 */
PlayerDict GameEngine::readFromDispatcher() {}

/**
 * Launch the game, manage it while it's not finished
 * GLHF!
 */
void GameEngine::play() {
    PlayerDict playerActions;
    while (this->players.size() > 1) {
        playerActions = this->readFromDispatcher();
        this->updateBoard(playerActions);
        this->sendToDispatcher();
    }
    std::cout << "FINISHED !" << std::endl;
}
