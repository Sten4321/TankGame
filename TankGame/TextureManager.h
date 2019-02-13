#pragma once
#ifndef TEXTUREMANAGER
#define TEXTUREMANAGER
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager
{
private:

	// Array of textures used
	std::map<std::string, sf::Texture> textures;

	TextureManager();
	~TextureManager();
public:
	static TextureManager& getInstance()
	{
		static TextureManager instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
	// Add a texture from a file
	void loadTexture(const std::string& name, const std::string &filename);

	// Translate an id into a reference
	sf::Texture& getRef(const std::string& texture);

	TextureManager(TextureManager const&) = delete;
	void operator=(TextureManager const&) = delete;
};

#endif