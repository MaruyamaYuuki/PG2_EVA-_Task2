#pragma once
#include <Novice.h>
#include"Struct.h"

class Enemy
{
public: 
	Enemy();

	void Update();
	void Draw();
	void SetSpeed(float speed);
	void SetPosY(float y);
	Vector2 GetPos() { return pos_; }
	int GetRadius() { return radius_; }
	int EnemyDed();
	void Damage();
	void HitAction();
	void Reset();

private:
	Vector2 pos_;
	int radius_;
    int alive;
	float speed_;
	int HP;
	unsigned int color;
	int hit;
	int hitTime;
};

