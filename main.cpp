#include <Novice.h>
#include <SafeDelete.h>

#include "./Function/Include/struct.h"
#include "./Camera/Include/Camera.h"
#include "./Camera/Include/BackFrame.h"

#include "Ball.h"

const char kWindowTitle[] = "LC1A_20_ヒサイチ_コウキ";

int Ball::ballCount;
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	
	Novice::Initialize(kWindowTitle, kWindowSizeX, kWindowSizeY);

	Camera* camera = new Camera;
	BackFrame* frame = new BackFrame;

	Ball* ball1 = new Ball;
	Ball* ball2 = new Ball;
	ball2->SetPos({ 320, 960 });
	ball2->SetAirResist(false);

	bool isMove = false;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///------------------///
		/// ↓更新処理ここから
		///------------------///

	
		if (keys[DIK_SPACE])
		{
			isMove = true;
		}
		camera->Update(keys);
		frame->Update();


		if (isMove)
		{
			ball1->Update();
			ball2->Update();
		}
		


		///------------------///
		/// ↑更新処理ここまで
		///------------------///

		///------------------///
		/// ↓描画処理ここから
		///------------------///


		frame->Draw(camera);
		ball1->Draw(camera);
		ball2->Draw(camera);
		ball1->Debug({ 0,0 });
		ball2->Debug({ 0,100 });



		///------------------///
		/// ↑描画処理ここまで
		///------------------///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	SafeDelete(camera);
	SafeDelete(frame);
	
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
