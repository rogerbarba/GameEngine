#pragma once

#include "raylib.h"

class Audio
{
public:
	// Sounds
	void playSound(Sound sound);
	void stopSound(Sound sound);
	void pauseSound(Sound sound);
	void resumeSound(Sound sound);
	bool isSoundPlaying(Sound sound);
	void setSoundVolume(Sound sound, float volume);
	void setSoundPitch(Sound sound, float pitch);
	void setSoundPan(Sound sound, float pan);

	// Music
	void playMusic(Music music);
	void updateMusic(Music music);
	void stopMusic(Music music);
	void pauseMusic(Music music);
	void resumeMusic(Music music);
	bool isMusicPlaying(Music music);
	void setMusicVolume(Music music, float volume);
	void setMusicPitch(Music music, float pitch);
	void setMusicPan(Music music, float pan);
	void seekMusic(Music music, float position);
	float getMusicTimeLength(Music music);
	float getMusicTimePlayed(Music music);

	// Other
	void setMasterVolume(float volume);
	float getMasterVolume(void);
};