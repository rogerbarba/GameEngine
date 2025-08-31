#include "Audio.hpp"

void Audio::playSound(Sound sound) { PlaySound(sound); }
void Audio::stopSound(Sound sound) { StopSound(sound); }
void Audio::pauseSound(Sound sound) { PauseSound(sound); }
void Audio::resumeSound(Sound sound) { ResumeSound(sound); }
bool Audio::isSoundPlaying(Sound sound) { return IsSoundPlaying(sound); }
void Audio::setSoundVolume(Sound sound, float volume) { SetSoundVolume(sound, volume); }
void Audio::setSoundPitch(Sound sound, float pitch) { SetSoundPitch(sound, pitch); }
void Audio::setSoundPan(Sound sound, float pan) { SetSoundPan(sound, pan); }

void Audio::playMusic(Music music) { PlayMusicStream(music); }
void Audio::updateMusic(Music music) { UpdateMusicStream(music); }
void Audio::stopMusic(Music music) { StopMusicStream(music); }
void Audio::pauseMusic(Music music) { PauseMusicStream(music); }
void Audio::resumeMusic(Music music) { ResumeMusicStream(music); }
bool Audio::isMusicPlaying(Music music) { return IsMusicStreamPlaying(music); }
void Audio::setMusicVolume(Music music, float volume) { SetMusicVolume(music, volume); }
void Audio::setMusicPitch(Music music, float pitch) { SetMusicPitch(music, pitch); }
void Audio::setMusicPan(Music music, float pan) { SetMusicPan(music, pan); }
void Audio::seekMusic(Music music, float position) { SeekMusicStream(music, position); }
float Audio::getMusicTimeLength(Music music) { return GetMusicTimeLength(music); }
float Audio::getMusicTimePlayed(Music music) { return GetMusicTimePlayed(music); }

void Audio::setMasterVolume(float volume) { SetMasterVolume(volume); }
float Audio::getMasterVolume(void) { return GetMasterVolume(); }