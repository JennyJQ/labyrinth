#include "ObstacleEntity.h"
#include <SFML/Graphics.hpp>

using namespace Game;

ObstacleEntity::ObstacleEntity()
{
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetFillColor(sf::Color::Transparent);
	m_renderComponent->SetTexture(GameEngine::eTexture::Obstacle);
	m_renderComponent->SetZLevel(2);
	m_renderComponent->SetTileIndex(0, 0);
}


ObstacleEntity::~ObstacleEntity()
{
}

void ObstacleEntity::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void ObstacleEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}