#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "LC1B_24_マルヤマユウキ_BLACK SHOT";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player();
	Enemy* boss = new Enemy();

	enum Scene {
		title,
		play,
		clear,
		gameover,
	};
	Scene scene = title;
	int gameStart = false;

	int Title = Novice::LoadTexture("./Resources/title.png");
	int Ctrl = Novice::LoadTexture("./Resources/ctrl.png");
	int Clear = Novice::LoadTexture("./Resources/clear.png");
	int GameOver = Novice::LoadTexture("./Resources/gameover.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (scene)
		{
		case title:
			player->Reset();
			boss->Reset();
			gameStart = false;
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = play;
			}
			break;
		case play:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				gameStart = true;
			}
			if (gameStart) {
		        player->Move(keys);
		        boss->Update();

		        if (player->HitBullet(boss->GetPos(), boss->GetRadius())) {
			        boss->Damage();
		        }
				boss->HitAction();

			    if (boss->EnemyDed()) {
				    scene = clear;
			    }
			}
			player->HitEnemy(boss->GetPos(), boss->GetRadius());
			if (!player->CheckAlive()) {
				scene = gameover;
			}

			break;
		case clear:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = title;
			}
			break;
		case gameover:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = title;
			}
			break;
		default:
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (scene)
		{
		case title:
			Novice::DrawSprite(0, 0, Title, 1, 1, 0.0f, WHITE);
			break;
		case play:

			Novice::DrawBox(0, 0, 1280, 740, 0.0f, BLACK, kFillModeSolid);
		    player->Draw();
		    boss->Draw();
			if (!gameStart) {
				Novice::DrawSprite(0, 0, Ctrl, 1, 1, 0.0f, WHITE);
			}
		 	break;
		case clear:
			Novice::DrawBox(0, 0, 1280, 740, 0.0f, WHITE, kFillModeSolid);
			Novice::DrawSprite(0, 0, Clear, 1, 1, 0.0f, WHITE);
			break;
		case gameover:
			Novice::DrawSprite(0, 0, GameOver, 1, 1, 0.0f, WHITE);
			break;
		default:
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	delete boss;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
