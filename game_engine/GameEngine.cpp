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
void GameEngine::updateBombs() {

	for(i=0;i<this.bombList.size();i++)
		if(this.bombList[i].second > 1)
			this.bombList.delay= this.bombList.second-1; 
		else
			this.bombsToExplode.insert(bombList[i]);

		this.explodeAndKill()

	}

/**
 * Explode the bomb with no timer left and kill the player in the radius
 */
	void GameEngine::explodeAndKill() {

		int j=0;
		int x,y;
		int coord[]
		std::vector<T> deathCell[];
		std::vector<T> newdeathCell[];
		int caseValue;	
		int val;

		for(i=0;i<this.bombsToExplode.size();i++){
			realpos=this.bombsToExplode[i].first;
			coord = this.getCoordinate(realpos);
			x=coord[0];
			y=coord[1];

			board[realpos]='_'
			this
			deathCell = this.getDeathCell(x,y);	
		}

		for(i=0;i<deathCell.size();i++){
			caseValue = deathCell[i];
			switch(caseValue)
			{

				case '#': board[caseValue]='_'
				case 'o': {
					coord = this.getCoordinate(caseValue)
					x=coord[0];
					y=coord[1];
					newDeathCell = this.getDeathCell(x,y)
					for(j=0;j<newDeathCell.size();j++){
						deathCell.push_back(newDeathCell(j));
						case '1': { board[caseValue]='_';  } 
						case '2': { board[caseValue]='_'; } 
						case '3': { board[caseValue]='_'; }
						case '4': { board[caseValue]='_'; } 
					}
				}
			}
		}
	}


	int[] GameEngine::getCoordinate(pos)
	{
		coord = [];
		x = pos % this.width;
		do{
			p=this.width*j+x;
			j++;
		}while(pos!=p);

		y = j;
		coord[0]=x;
		coord[1]=y;

		return coord;
	}

	void GameEngine::killPlayer(playerId)
	{
  // erase fonctionne avec key sinon utiliser find puis "it.erase"
		this.PlayerDict.erase(playerId)
		this.PlayerPosition.erase(playerId)
	}

	std::vector<T> GameEngine::getDeathCell(x,y)
	{
		int i=0;
		std::vector<T> explosion;
		int bombPos = y*this.width+x;
		int colDeath;

		for(i=bombPos-this.radius;i<bombpos+this.radius;i>this.width*(y-1)+1;i>this.width*(y+1)-1;l++){
			explosion.push_back(i);

			if(l<=this.radius)
				colDeath=bombPos-(this.radius-l)*this.width
			else
				colDeath=bombPos+(l-this.radius)*this.width

			if(colDeath > this.width+1 && colDeath<this.width*(this.height-1)-1)
				explosion.push_back(bombPos-(this.radius-l)*this.width)
			else
				explosion.push_back(bombPos+(l-this.radius)*this.width)

			return explosion;
		}

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
		void GameEngine::updateBombs() {

			for(i=0;i<this.bombList.size();i++)
				if(this.bombList[i].second > 1)
					this.bombList.delay= this.bombList.second-1; 
				else
					this.bombsToExplode.insert(bombList[i]);

				this.explodeAndKill()

			}

/**
 * Explode the bomb with no timer left and kill the player in the radius
 */
			void GameEngine::explodeAndKill() {

				int j=0;
				int x,y;
				int coord[]
				std::vector<T> deathCell[];
				std::vector<T> newdeathCell[];
				int caseValue;	
				int val;

				for(i=0;i<this.bombsToExplode.size();i++){
					realpos=this.bombsToExplode[i].first;
					coord = this.getCoordinate(realpos);
					x=coord[0];
					y=coord[1];

					board[realpos]='_'
					this
					deathCell = this.getDeathCell(x,y);	
				}

				for(i=0;i<deathCell.size();i++){
					caseValue = deathCell[i];
					switch(caseValue)
					{

						case '#': board[caseValue]='_'
						case 'o': {
							coord = this.getCoordinate(caseValue)
							x=coord[0];
							y=coord[1];
							newDeathCell = this.getDeathCell(x,y)
							for(j=0;j<newDeathCell.size();j++)
								deathCell.push_back(newDeathCell(j));
									case '1': { board[caseValue]='_';  } 
									case '2': { board[caseValue]='_'; } 
									case '3': { board[caseValue]='_'; }
									case '4': { board[caseValue]='_'; } 

								}

							}
						}

					}
				}

			int[] getCoordinate(pos)
			{
				coord = [];
				x = pos % this.width;
				do{
					p=this.width*j+x;
					j++;
				}while(pos!=p);

				y = j;
				coord[0]=x;
				coord[1]=y;

				return coord;
			}

			void killPlayer(playerId)
			{
  // erase fonctionne avec key sinon utiliser find puis "it.erase"
				this.PlayerDict.erase(playerId)
				this.PlayerPosition.erase(playerId)
			}

			std::vector<T> getDeathCell(x,y)
			{
				int i=0;
				std::vector<T> explosion;
				int bombPos = y*this.width+x;
				int colDeath;

				for(i=bombPos-this.radius;i<bombpos+this.radius;i>this.width*(y-1)+1;i>this.width*(y+1)-1;l++){
					explosion.push_back(i);

					if(l<=this.radius)
						colDeath=bombPos-(this.radius-l)*this.width
					else
						colDeath=bombPos+(l-this.radius)*this.width

					if(colDeath > this.width+1 && colDeath<this.width*(this.height-1)-1)
						explosion.push_back(bombPos-(this.radius-l)*this.width)
					else
						explosion.push_back(bombPos+(l-this.radius)*this.width)

					return explosion;
				}

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
