#pragma once
#include "Struct.h"


class Bullet{
public:

	Bullet();
	void Update();
	void Draw();
	float Setspeed(float speed) {
		for (int i = 0; i < 32; i++) {
			speed_[i] = speed;
			return speed_[i];
		}
	}
public:

	Vector2 pos_[32];
	float radius_[32];
	float speed_[32];
	int isShot_[32];
	int shotCoolTime;
};

