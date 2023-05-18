#include <iostream>
#include "ChessBoard.h"
#include <memory>

using namespace std;
bool isNumber(const char& str)
{
	if (std::isdigit(str) == 0) return false;
	return true;
}
ChessBoard::ChessBoard() {
	std::string startsetchess = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
	int i = 0; int a = 0; int b = 0; int x = 0;
	while (i < startsetchess.size()) {
		while ((startsetchess[i] != '/') && (i < startsetchess.size())) 
		{

				//---------------White-------------------//
			if (startsetchess[i] == 'r') {
				chessboard[a][b] = std::make_unique<Rook>(a, b, 'r', true);
			}
			if (startsetchess[i] == 'n') {
				chessboard[a][b] = std::make_unique<Knight>(a, b, 'n', true);
			}
			if (startsetchess[i] == 'b') {
				chessboard[a][b] = std::make_unique <Bishop>(a, b, 'b', true);
			}
			if (startsetchess[i] == 'q') {
				chessboard[a][b] = std::make_unique<Queen>(a, b, 'q', true);
			}
			if (startsetchess[i] == 'k') {
				chessboard[a][b] = std::make_unique<King>(a, b, 'k', true);
			}
			if (startsetchess[i] == 'p') {
				chessboard[a][b] = std::make_unique<Pawn>(a, b, 'p', true);
			}

				//-------------------Black----------------//
			if (startsetchess[i] == 'P') {
				chessboard[a][b] = std::make_unique<Pawn>(a, b, 'P', false);
			}
			if (startsetchess[i] == 'R') {
				chessboard[a][b] = std::make_unique<Rook>(a, b, 'R', false);
			}
			if (startsetchess[i] == 'N') {
				chessboard[a][b] = std::make_unique<Knight>(a, b, 'N', false);
			}
			if (startsetchess[i] == 'B') {
				chessboard[a][b] = std::make_unique<Knight>(a, b, 'B', false);
			}
			if (startsetchess[i] == 'Q') {
				chessboard[a][b] = std::make_unique<Queen>(a, b, 'Q', false);
			}
			if (startsetchess[i] == 'K') {
				chessboard[a][b] =std::make_unique<King>(a, b, 'K', false);
			}
			if (isNumber(startsetchess[i])) {
					x = b;
					int buf = startsetchess[i] - 48;
					b = b + buf;
					for (int j = x; j < b; j++) {
						chessboard[a][j] = nullptr;
					}	
			}
			i++;
			b++;
		}
		i++;
		b = 0;
		a++;
	}
}
ChessBoard::~ChessBoard() {}


