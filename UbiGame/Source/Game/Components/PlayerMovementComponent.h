#pragma once
#include "GameEngine\EntitySystem\Component.h"

namespace Game
{
	class GameBoard;

	class PlayerMovementComponent : public GameEngine::Component
	{
	public:
		PlayerMovementComponent();
		~PlayerMovementComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

		void SetBoard(GameBoard* board) { m_board = board; }
		
	private:
		bool m_wasFaceSwapButtonPressed;
		bool m_wasRightPressed;
		bool m_wasLeftPressed;
		bool m_wasUpPressed;
		bool m_wasDownPressed;
		int m_numSteps;
		float m_x;
		float m_y;
		bool m_isGameOver;



		GameBoard* m_board;
	};
}