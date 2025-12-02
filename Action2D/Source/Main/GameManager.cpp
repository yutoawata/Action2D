#include "GameManager.h"


//コンストラクタ
GameManager::GameManager() {
	//解像度を設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR);

	//フルスクリーンにする
	ChangeWindowMode(FALSE);
	isError = DxLib_Init();

	//Zバッファの使用を許可
	SetUseZBuffer3D(TRUE);
	//Zバッファの書き込みを許可
	SetWriteZBuffer3D(TRUE);
	//マウスカーソルの表示をON
	SetMouseDispFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);

	isTitle = true;
}

//デストラクタ
GameManager::~GameManager() {}

void GameManager::Run() {
	while (!ProcessMessage() && isError != TRUE) {

		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}

		ClearDrawScreen();

		if (isTitle) {
			ShowTitle();
		}
		else if(!isPlay) {
			ShowResult();
		}

		PlayGame();

		ScreenFlip();
	}
}

void GameManager::ShowTitle() {

}

void GameManager::PlayGame() {
	dungeon->Draw();
}

void GameManager::ShowResult() {

}