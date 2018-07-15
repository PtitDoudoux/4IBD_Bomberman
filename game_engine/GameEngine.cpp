#include "GameEngine.h"

/**
 * Default constructor
 */
GameEngine::GameEngine() {
	this->width = 20;
	this->height= 20;
	this->delay = 6;
	this->radius = 5;
	this->maxBombs = 10;
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
void GameEngine::generateBoard() {}

/**
 * Instantiate the players with their position
 */
void GameEngine::instantiatePlayers() {}


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
void GameEngine::executePlayersActions(PlayerDict playersActions) {}


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
