#pragma once
#include <fmod.hpp>

//사운드 채널 갯수 정의
#define SOUND_NUM 10

#ifdef _WIN64
#pragma comment(lib, "fmodL64_vc.lib")
#elif _WIN32
#pragma comment(lib, "fmodL_vc.lib")
#endif

using namespace FMOD;


class CSound
{
public:
	CSound();
	virtual ~CSound();
	System * pSystem;
	Sound * pSound[SOUND_NUM];
	Channel * pChannel[SOUND_NUM];

	void Add_sound();
	void Play(int n);
};

