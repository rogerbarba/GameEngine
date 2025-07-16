#pragma once

#include "raylib.h"
#include <unordered_map>
#include <string>

class ResourceManager
{
private:
	std::unordered_map<std::string, Texture2D> textures;
	std::unordered_map<std::string, Sound> sounds;
	std::unordered_map<std::string, Music> musics;
	std::unordered_map<std::string, Font> fonts;

public:
	// Textures
	Texture2D& loadTexture(const std::string& name, const char* fileName);
	Texture2D& getTexture(const std::string& name);

	// Sound and music
	Sound& loadSound(const std::string& name, const char* fileName);
	Sound& getSound(const std::string& name);

	Music& loadMusic(const std::string& name, const char* fileName);
	Music& getMusic(const std::string& name);

	// Fonts
	Font& loadFont(const std::string name, const char* fileName);
	Font& getFont(const std::string name);

	// Unloads
	void unloadAll();
};