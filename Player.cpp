#include "Player.h"
#include "Novice.h"

Player::Player() {
	pos_ = { 640,360 };
	radius_ = 30;
	speed_ = 8;
	alive = true;

	bullet_ = new Bullet();
}

Player::~Player() {
	delete bullet_;
}

void Player::Move(char* keys) {
	if (keys[DIK_W]) {
		if (pos_.y - radius_ > 0) {
		    pos_.y -= speed_;
		}
	}
	if (keys[DIK_S]) {
		if (pos_.y + radius_ < 740) {
		    pos_.y += speed_;
		}
	}
	if (keys[DIK_A]) {
		if (pos_.x - radius_ > 0) {
	        pos_.x -= speed_;
		}
	}
	if (keys[DIK_D]) {
		if (pos_.x + radius_ < 1280) {
		    pos_.x += speed_;
		}
	}

	if (keys[DIK_SPACE]) {
		if (bullet_->shotCoolTime > 0) {
			bullet_->shotCoolTime--;
		}
		else {
			bullet_->shotCoolTime = 15;
		}
	}
	if (bullet_->shotCoolTime <= 0) {
		for (int i = 0; i < 32; i++) {
			if (bullet_->isShot_[i] == 0) {
				bullet_->isShot_[i] = true;
				bullet_->pos_[i] = pos_;
				break;
			}
		}
	}

	bullet_->Update();
}

void Player::Draw() {
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, WHITE, kFillModeSolid);

	bullet_->Draw();
}

int Player::HitBullet(Vector2 pos, int radius) {

	for (int i = 0; i < 32; i++) {

	    float dx = pos.x - bullet_->pos_[i].x;
	    float dy = pos.y - bullet_->pos_[i].y;

	    float combonedRadius = float(radius + bullet_->radius_[i]);
		
	    if ((dx * dx + dy * dy) < (combonedRadius * combonedRadius)) {
			bullet_->isShot_[i] = false;
			return true;
	    }
	}
	return false;
}

void Player::HitEnemy(Vector2 pos, int radius) {

	float dx = pos.x - pos_.x;
	float dy = pos.y - pos_.y;

	float combonedRadius = float(radius + radius_);

	if ((dx * dx + dy * dy) < (combonedRadius * combonedRadius)) {
		alive = false;

	}
}

int Player::CheckAlive() {
	if (alive) {
		return true;
	}
	return false;
}

void Player::Reset() {
	pos_ = { 640,360 };
	for (int i = 0; i < 32; i++) {
		bullet_->pos_[i] = { 0,0 };
		bullet_->radius_[i] = 10;
		bullet_->speed_[i] = 15;
		bullet_->isShot_[i] = false;
	}
	alive = true;
	bullet_->shotCoolTime = 15;
}