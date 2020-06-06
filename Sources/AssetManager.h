#ifndef ASSETMANAGER
#define ASSETMANAGER

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager
{
private:
	std::map<std::string, sf::Texture> texturesMap;
	std::map<std::string, sf::Font> fontsMap;
	std::map<std::string, sf::SoundBuffer> bufferMap;

public:
	AssetManager() {}
	virtual ~AssetManager() {}

	//methodes
	void loadTexture(std::string _name, std::string _filepath);
	sf::Texture &getTexture(std::string _name);

	void loadFont(std::string _name, std::string _filepath);
	sf::Font &getFont(std::string _name);

	void loadBuffer(std::string _name, std::string _filepath);
	sf::SoundBuffer &getBuffer(std::string _name);
};
#endif // !ASSETMANAGER
