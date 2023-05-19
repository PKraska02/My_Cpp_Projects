#pragma once
#include "Chess.h"

class Rook :public Figure {
public:
	//bool CheckRookRules();
	virtual void Move() const;
};
