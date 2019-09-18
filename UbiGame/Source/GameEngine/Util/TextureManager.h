#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Player,
			BG,
			Obstacle,
			Tile1,
			Tile2,
			Tile3,
			Tile4,
			test,
			Bed,
			Count,
			Portal
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::Player: return "character-and-extradance.png";
		case eTexture::BG: return "cobblestone.jpg";
		case eTexture::test: return "tileset.png";//test
		case eTexture::Bed: return "bed.png";
		case eTexture::Obstacle: return "fog.jpg";
		case eTexture::Tile1: return "1.png";
		case eTexture::Tile2: return "2.png";
		case eTexture::Tile3: return "3.png";
		case eTexture::Tile4: return "4.png";
		case eTexture::Portal: return "portal.png";
		}

		return "UnknownTexType";
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	static sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
	{
		switch (texture)
		{
			case  GameEngine::eTexture::Player:  return sf::Vector2f(50.f, 50.f);
		}

		return sf::Vector2f(-1.f, -1.f);
	}
}

