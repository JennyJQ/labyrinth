#pragma once
#include "GameEngine\EntitySystem\Entity.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"

namespace Game
{

	class NumberEntity : public GameEngine::Entity
	{
	public:
		NumberEntity::NumberEntity(const int num);
		NumberEntity::~NumberEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}
