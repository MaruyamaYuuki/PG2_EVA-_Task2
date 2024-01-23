#pragma once
#include "Struct.h"
#include "Bullet.h"

class Player {
public:

	Player();
	~Player();

	void Draw();
	void Move(char* keys );
	int HitBullet(Vector2 pos_, int radius);
	void Reset();

private:
	Vector2 pos_;
	float radius_;
	float speed_;

	Bullet* bullet_;
};
