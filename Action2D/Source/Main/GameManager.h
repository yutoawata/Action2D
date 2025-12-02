#pragma once
#include <memory>
#include "DxLib.h"
#include "../Map/Dungeon.h"

class GameManager
{
public:
	//コンストラクタ
	GameManager();
	//デストラクタ
	~GameManager();

	void Run();

private:
	void ShowTitle();
	void PlayGame();
	void ShowResult();

	static const int SCREEN_WIDTH{ 1920 };
	static const int SCREEN_HEIGHT{ 1080 };
	static const int SCREEN_COLOR{ 32 };

	std::unique_ptr<Dungeon> dungeon{ std::make_unique<Dungeon>(40, 40) };
	int isError{ FALSE };
	bool isPause{ false };//ポーズフラグ
	bool isTitle{ false };
	bool isPlay{ false };
};

