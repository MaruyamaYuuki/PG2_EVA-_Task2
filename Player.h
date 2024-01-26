#pragma once
#include "Struct.h"
#include "Bullet.h"

class Player {
public:

	Player();
	~Player();

	void Draw();
	void Move(char* keys );
	int HitBullet(Vector2 pos, int radius);
	void HitEnemy(Vector2 pos, int radius);
	int CheckAlive();
	void Reset();

private:
	Vector2 pos_;
	float radius_;
	float speed_;
	int alive;

	Bullet* bullet_;
};
