#include "MathMethod.h"

//intŒ^‚Ìâ‘Î’l‚ğæ“¾
int GetAbsoluteInt(int value_) {
	return (value_ > 0) ? value_ : -value_;
}

//floatŒ^‚Ìâ‘Î—˜‚ğæ“¾
float GetAbsoluteFloat(float value_) {
	return (value_ > 0.0f) ? value_ : -value_;
}

//—”¶¬ŠÖ”(intŒ^)
int CreateRandom(int min_, int max_) {
    std::random_device rd;

    std::mt19937 engine(rd());

    std::uniform_int_distribution<int> dist(min_, max_);

    int result = dist(engine);
    return result;
}