#pragma once
#include <unordered_map>
#include "SFML/Graphics.hpp"
using namespace std;

class TextureManager
{
public:
	enum AssetType { BG = 0, Eagle = 1, Raptor = 2, Spike = 4, Avenger = 5, UI_BG = 6, ButtonNormal = 7, ButtonPressed = 8, HUD_BG = 9};
	enum FontType {DefaultFont = 0};
	static TextureManager* getInstance();
	void loadAll();
	sf::Texture* getTextureAt(TextureManager::AssetType assetType, int index);
	int getTextureLength(TextureManager::AssetType assetType);
	sf::Font* getFont(FontType fontType);


	void testFunction();

private:
	TextureManager() {};
	TextureManager(TextureManager const&) {};             // copy constructor is private
	TextureManager& operator=(TextureManager const&) {};  // assignment operator is private
	static TextureManager* sharedInstance;

	unordered_map<TextureManager::AssetType, vector<sf::Texture*>> textureMap;
	unordered_map<TextureManager::FontType, sf::Font*> fontMap;

};