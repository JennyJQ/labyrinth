#include "NumberEntity.h"
#include <SFML/Graphics.hpp>

using namespace Game;



NumberEntity::NumberEntity(const int num)
{
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	//m_renderComponent->SetFillColor(sf::Color::Red);
	if(num == 2)
	m_renderComponent->SetTexture(GameEngine::eTexture::Tile1);
	else if (num == 3)
	m_renderComponent->SetTexture(GameEngine::eTexture::Tile2);
	else if (num == 4)
	m_renderComponent->SetTexture(GameEngine::eTexture::Tile3);
	else if (num == 5)
	m_renderComponent->SetTexture(GameEngine::eTexture::Tile4);

	m_renderComponent->SetZLevel(2);
	m_renderComponent->SetTileIndex(0, 0);
}


NumberEntity::~NumberEntity()
{
}

void NumberEntity::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void NumberEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}