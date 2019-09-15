#pragma once
#include "GameEngine\EntitySystem\Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();


		void Update();		
		bool IsGameOver() { return false; }
		//void UpdateTile();
		void PlayerUpdate(const int xCor, const int yCor);
		void DeleteBlocks();
	private:
		void CreatePlayer(float xpos, float ypos, float width, float height);
		void CreateObstacle(float xpos, float ypos, float width, float height);
		void CreateBackGround();
		void OpenSpace(const int a, const int b);
		

		void MakeGrid();
		void CreateDark(const sf::Vector2f& pos, const sf::Vector2f& size);
		void CreateNumTiles(const sf::Vector2f& pos, const sf::Vector2f& size,int num);
		std::vector<GameEngine::Entity*> m_blocks; //Array for blocks
		GameEngine::Entity* m_player;
		GameEngine::Entity* m_backGround;
		int** tiles = new int*[20];

		bool m_isGameOver;
	};
}

