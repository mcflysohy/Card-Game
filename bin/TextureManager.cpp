#include "TextureManager.hpp"

void TextureManager::loadTexture(std::string name, std::string filename)
{
	// load the texture
	sf::Texture tex;
	if ( tex.loadFromFile(filename) )
	{
		// add it to the map of textures
		this->allTextures[name]= tex;
	}

	return;
}

sf::Texture &TextureManager::getRef(std::string name)
{
	return this->allTextures.at(name);
}
