#include "PlayerMovementComponent.h"
#include "GameEngine\GameEngineMain.h"
#include "Game\GameBoard.h"

#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"

#include <SFML/Window/Keyboard.hpp>

using namespace Game;

PlayerMovementComponent::PlayerMovementComponent()
	: m_wasFaceSwapButtonPressed(false)
	, m_wasRightPressed(false)
	, m_wasLeftPressed(false)
	, m_wasUpPressed(false)
	, m_wasDownPressed(false)
	, m_numSteps(0)
	, m_x(25)
	, m_y(25)
{

}


PlayerMovementComponent::~PlayerMovementComponent()
{

}

void PlayerMovementComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}

/*{if (m_board)
		{
			m_board->PlayerUpdate(275, 325);
		}*/
void PlayerMovementComponent::Update()
{
	__super::Update();

	//Grabs how much time has passed since the last Update() call
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	//by default the wanted velocity is 0
	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);
	//player Velocity is applied when we have some input (for the time being let's make it 10pixels a second)
	//float playerVel = 100.f;

	int maxNumSteps = 50;
	float pxPerStep = 1;

	GameEngine::AnimationComponent* animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_numSteps == 0)
	{
		m_wasLeftPressed = true;
	}
	else
	{
		if (m_wasLeftPressed)
		{
			if (animComponent)
			{
				animComponent->SetIsLooping(true);
				animComponent->PlayAnim(GameEngine::EAnimationId::PlayerWalkLeft);
			}
			wantedVel.x -= pxPerStep;
			m_x -= pxPerStep;
			m_numSteps += 1;
		}
		if (m_numSteps == maxNumSteps)
		{
			m_wasLeftPressed = false;
			m_numSteps = 0;
			m_board->PlayerUpdate(m_x, m_y);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_wasRightPressed = true;
	}
	else
	{
		if (m_wasRightPressed)
		{
			if (animComponent)
			{
				animComponent->SetIsLooping(true);
				animComponent->PlayAnim(GameEngine::EAnimationId::PlayerWalkRight);
			}
			wantedVel.x += pxPerStep;
			m_x += pxPerStep;
			m_numSteps += 1;
		}
		if (m_numSteps == maxNumSteps)
		{
			m_wasRightPressed = false;
			m_numSteps = 0;
			m_board->PlayerUpdate(m_x, m_y);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_wasUpPressed = true;
	}
	else
	{
		if (m_wasUpPressed)
		{
			if (animComponent)
			{
				animComponent->SetIsLooping(true);
				animComponent->PlayAnim(GameEngine::EAnimationId::PlayerWalkUp);
			}
			wantedVel.y -= pxPerStep;
			m_y -= pxPerStep;
			m_numSteps += 1;
		}
		if (m_numSteps == maxNumSteps)
		{
			m_wasUpPressed = false;
			m_numSteps = 0;
			m_board->PlayerUpdate(m_x, m_y);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_wasDownPressed = true;
	}
	else
	{
		if (m_wasDownPressed)
		{
			if (animComponent)
			{
				animComponent->SetIsLooping(true);
				animComponent->PlayAnim(GameEngine::EAnimationId::PlayerWalkDown);
			}
			wantedVel.y += pxPerStep;
			m_y += pxPerStep;
			m_numSteps += 1;
		}
		if (m_numSteps == maxNumSteps)
		{
			m_wasDownPressed = false;
			m_numSteps = 0;
			m_board->PlayerUpdate(m_x, m_y);
		}
	}

	

	int maxFaces = 4;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		m_wasFaceSwapButtonPressed = true;
	}
	else
	{
		//Button is not pressed now, but it was pressed last frame, which means it just has been released
		if (m_wasFaceSwapButtonPressed)
		{
			GameEngine::AnimationComponent* animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
			if (animComponent)
			{
				animComponent->SetIsLooping(false);
				animComponent->PlayAnim(GameEngine::EAnimationId::PlayerDance);
			}
		}

		m_wasFaceSwapButtonPressed = false;
	}



	//Update the entity position with new velocity
	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);
}