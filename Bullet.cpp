#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet() {
	for (int i = 0; i < 32; i++) {
	    pos_[i] = {0,0};
	    radius_[i] = 10;
	    speed_[i] = 15;
	    isShot_[i] = false;
	}
	shotCoolTime = 15;
}

void Bullet::Update() {
	for (int i = 0; i < 32; i++) {
	    if (isShot_[i]) {
		    pos_[i].y -= speed_[i];
	    }
	    if (pos_[i].y + radius_[i] <= 0) {
		    isShot_[i] = false;
	    }

	}
}

void Bullet::Draw() {
	for (int i = 0; i < 32; i++) {
	    if (isShot_[i]) {
		    Novice::DrawEllipse(int(pos_[i].x), int(pos_[i].y), int(radius_[i]), int(radius_[i]), 0.0f, WHITE, kFillModeSolid);
	    }
	}

}

