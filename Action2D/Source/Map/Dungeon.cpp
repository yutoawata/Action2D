#include "Dungeon.h"

//コンストラクタ
Dungeon::Dungeon(int width_, int height_)
	: width(width_), height(height_) {

	if (width < DOWM_LIMIT_CELL_VALUE || height < DOWM_LIMIT_CELL_VALUE) {
		throw std::out_of_range("5 * 5以上の大きさである必要があります");
	}

	if (width_ % 2 == 0) {
		width++;
	}

	if (height_ % 2 == 0) {
		height++;
	}

	maze = std::vector<std::vector<int>>(height, std::vector<int>(width));

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
				maze[y][x] = AISLE;//判定用に外壁を通路にしておく
			}
			else {
				maze[y][x] = WALL;//初めに壁で埋める
			}
		}
	}

	Create();
}
//デストラクタ
Dungeon::~Dungeon() {

}

//マップ生成用処理
void Dungeon::Create() {
	Digging(Vector2(1, 1));

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
				maze[y][x] = WALL;//通路にしていた外壁を壁に直す
			}
		}
	}
}

void Dungeon::Digging(Vector2 index_) {
	int rand = CreateRandom(0, 3);

	while (true) {
		std::vector<Direction> directionList = std::vector<Direction>();

		if (maze[index_.y - 1][index_.x] == WALL && maze[index_.y - 2][index_.x] == WALL) {
			directionList.emplace_back(Direction::UP);
		}
		if (maze[index_.y][index_.x + 1] == WALL && maze[index_.y][index_.x + 2] == WALL) {
			directionList.emplace_back(Direction::RIGHT);
		}
		if (maze[index_.y + 1][index_.x] == WALL && maze[index_.y + 2][index_.x] == WALL) {
			directionList.emplace_back(Direction::DOWM);
		}
		if (maze[index_.y][index_.x - 1] == WALL && maze[index_.y][index_.x - 2] == WALL) {
			directionList.emplace_back(Direction::LEFT);
		}

		if (static_cast<int>(directionList.size()) == 0) {
			break;
		}
		SetAisleCell(index_.x,index_.y);

		int directionIndex = CreateRandom(0, static_cast<int>(directionList.size()) - 1);

		switch (directionList[directionIndex]) {
		case Direction::UP:
			SetAisleCell(index_.x, --index_.y);
			SetAisleCell(index_.x, --index_.y);
			break;
		case Direction::RIGHT:
			SetAisleCell(++index_.x, index_.y);
			SetAisleCell(++index_.x, index_.y);
			break;
		case Direction::DOWM:
			SetAisleCell(index_.x, ++index_.y);
			SetAisleCell(index_.x, ++index_.y);
			break;
		case Direction::LEFT:
			SetAisleCell(--index_.x, index_.y);
			SetAisleCell(--index_.x, index_.y);
			break;
		}
	}

	Vector2 startCell = GetStartCell();

	if (startCell != Vector2(-1, -1)) {
		Digging(startCell);
	}
}

void Dungeon::SetAisleCell(int x_, int y_) {
	maze[y_][x_] = AISLE;

	if (x_ % 2 == 1 && y_ % 2 == 1) {
		startCells.emplace_back(Vector2(x_, y_));
	}
}

Vector2 Dungeon::GetStartCell() {
	if (static_cast<int>(startCells.size()) == 0) {
		return Vector2(-1, -1);
	}

	int index = CreateRandom(0, static_cast<int>(startCells.size()) - 1);
	Vector2 cell = startCells[index];
	startCells.erase(startCells.begin() + index);

	return cell;
}

void Dungeon::Draw() {
	int w = (1080 / 2) / width;

	Vector2 basePosition = Vector2(1300, 450);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (maze[y][x] == WALL) {
				DrawBox(basePosition.x + w * x, basePosition.y + w * y,
						basePosition.x + w * (x + 1), basePosition.y + w * (y + 1),
						GetColor(0, 255, 0), TRUE);
			}
		}
	}
}