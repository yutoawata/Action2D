#pragma once
#include <iostream>
#include <vector>
#include "../Math/Vector2.h"
#include"../Math/MathMethod.h"

class Dungeon
{
	enum class Direction {
		UP,
		RIGHT,
		DOWM,
		LEFT
	};
public:
	//コンストラクタ
	Dungeon(int width_, int height_);
	//デストラクタ
	~Dungeon();

	void Draw();

	//マップ生成用処理
private:
	void Create();
	void Digging(Vector2 index_);
	void SetAisleCell(int x_, int y_);
	Vector2 GetStartCell();


	static const int DOWM_LIMIT_CELL_VALUE{ 5 };
	static const int AISLE{ 0 };
	static const int WALL{ 1 };


	std::vector<Vector2> startCells;
	std::vector<std::vector<int>> maze;
	int width{ 0 };
	int height{ 0 };


};

