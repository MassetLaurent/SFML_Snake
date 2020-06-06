#include "AssetManager.h"
#include <iostream>

//textures manager
void AssetManager::loadTexture(std::string _name, std::string _filepath)
{
	sf::Texture tempText;

	if(tempText.loadFromFile(_filepath))
		this->texturesMap[_name] = tempText;
}

sf::Texture& AssetManager::getTexture(std::string _name)
{
	return this->texturesMap.at(_name);
}


//fonts manager
void AssetManager::loadFont(std::string _name, std::string _filepath)
{
	sf::Font tempFont;
	
	if(tempFont.loadFromFile(_filepath))
		this->fontsMap[_name] = tempFont;
}

sf::Font & AssetManager::getFont(std::string _name)
{
	return this->fontsMap.at(_name);
}


//soundBuffer manager
void AssetManager::loadBuffer(std::string _name, std::string _filepath)
{
	sf::SoundBuffer tempBuffer;

	if(tempBuffer.loadFromFile(_filepath))
		this->bufferMap[_name] = tempBuffer;
}

sf::SoundBuffer & AssetManager::getBuffer(std::string _name)
{
	return this->bufferMap.at(_name);
}
