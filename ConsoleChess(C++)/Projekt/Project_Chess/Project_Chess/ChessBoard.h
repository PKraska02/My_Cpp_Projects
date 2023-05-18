#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Chess.h"
class Figure;
bool isNumber(const char& str);
class ChessBoard {
public:
	std::unique_ptr<Figure> chessboard[8][8];
	ChessBoard();
	~ChessBoard();
};
void Game(bool& iswhite);
void ChessBoardGenerator(ChessBoard& board);
void ReverseBoardGenerator(ChessBoard& board);
