#include "Enemy.h"

Enemy::Enemy() {
	pos_ = { 640,100 };
	radius_ = 50;
	speed_ = 10;
    alive = true;
	HP = 100;
	color = BLACK;
	hit = false;
	hitTime = 5;
}

void Enemy::Update() {
	if (HP > 0) {
	    pos_.x += speed_;
	    if (pos_.x + radius_ >= 1280 || pos_.x - radius_ <= 0) {
		    speed_ *= -1;
	    }
	}
}


void Enemy::Draw() {
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), radius_, radius_, 0.0f, color, kFillModeSolid);
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), radius_, radius_, 0.0f, WHITE, kFillModeWireFrame);
}

void Enemy::SetSpeed(float speed) {
	speed_ = speed;
}

void Enemy::SetPosY(float y) {
	pos_.y = y;
}

int Enemy::EnemyDed() {
	if (radius_ <= 0) {
		return true;
	}
	return false;
}

void Enemy::Damage() {
	hit = true;
	HP -= 5;
	if (HP <= 0) {
		alive = false;
	}
}

void Enemy::HitAction() {
	if (hit) {
	    if (hitTime > 0) {
		    color = WHITE;
		    hitTime--;
	    }
	    if (hitTime <= 0) {
		    color = BLACK;
			hit = false;
			hitTime = 5;
	    }
	}
	if (!alive) {
		color = WHITE;
		if (radius_ > 0) {
			radius_--;
		}
	}
}

void Enemy::Reset() {
	pos_ = { 640,100 };
	alive = true;
	HP = 100;
	radius_ = 50;
	color = BLACK;
}