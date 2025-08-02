#include "ResourceManager.hpp"

void ResourceManager::unloadAll()
{
	for (const auto& texturePair : textures)
	{
		UnloadTexture(texturePair.second);
	}

	for (const auto& soundPair : sounds)
	{
		UnloadSound(soundPair.second);
	}

	for (const auto& musicPair : musics)
	{
		UnloadMusicStream(musicPair.second);
	}

	for (const auto& fontPair : fonts)
	{
		UnloadFont(fontPair.second);
	}
}

Texture2D& ResourceManager::loadTexture(const std::string& name, const char* fileName)
{
	Texture2D texture = LoadTexture(fileName);

	textures.emplace(name, texture);

	return getTexture(name);
}

Texture2D& ResourceManager::getTexture(const std::string& name)
{
	return textures.at(name);
}

Sound& ResourceManager::loadSound(const std::string& name, const char* fileName)
{
	Sound sound = LoadSound(fileName);

	sounds.emplace(name, sound);

	return getSound(name);
}

Sound& ResourceManager::getSound(const std::string& name)
{
	return sounds.at(name);
}

Music& ResourceManager::loadMusic(const std::string& name, const char* fileName)
{
	Music music = LoadMusicStream(fileName);

	musics.emplace(name, music);

	return getMusic(name);
}

Music& ResourceManager::getMusic(const std::string& name)
{
	return musics.at(name);
}

Font& ResourceManager::loadFont(const std::string& name, const char* fileName)
{
	Font font = LoadFont(fileName);

	fonts.emplace(name, font);

	return getFont(name);
}

Font& ResourceManager::getFont(const std::string& name)
{
	return fonts.at(name);
}