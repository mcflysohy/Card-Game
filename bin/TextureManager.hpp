#ifndef TEXTURE_MANAGER_HPP_INCLUDED
#define TEXTURE_MANAGER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
	private:
		// array of textures used
		std::map<std::string, sf::Texture> allTextures;

	public:
		// add a texture from a file
		void loadTexture(std::string name, std::string filename);

		// translate an id into a reference
		sf::Texture &getRef(std::string name);

		// constructor
		TextureManager(){}
};

#endif // end of TEXTURE_MANAGER_HPP_INCLUDED