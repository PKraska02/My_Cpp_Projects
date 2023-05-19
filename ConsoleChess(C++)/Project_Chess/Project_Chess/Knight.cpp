#include <iostream>
#include "Chess.h"
#include "ChessBoard.h"
#include <memory>
using namespace std;

bool Knight::IsGoodMove(bool iswhite, int& rp, int& cp, int& nextrp, int& nextcp)
{
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;

	if (
		((nextrp == rp + 1 && (nextcp == cp + 2 || nextcp == cp - 2)) ||
		(nextrp == rp - 1 && (nextcp == cp + 2 || nextcp == cp - 2)) ||
		(nextrp == rp + 2 && (nextcp == cp + 1 || nextcp == cp - 1)) ||
		(nextrp == rp - 2 && (nextcp == cp + 1 || nextcp == cp - 1)))
		)
		return true;
	else
	return false;
}

bool Knight::CanMove(bool iswhite, int& rp, int& cp, int& nextrp, int& nextcp, char& name, ChessBoard& board)
{
	if (iswhite) {
		if (board.chessboard[nextrp][nextcp] == nullptr&& name=='n'&&board.chessboard[rp][cp]->iswhite==iswhite)
			return true;
		else {
			return false;
		}
	}
	else {
		if (board.chessboard[nextrp][nextcp] == nullptr && name == 'N')
			return true;
		else {
			return false;
		}
	}

}

bool Knight::CanHit(bool iswhite, int& rp, int& cp, int& nextrp, int& nextcp, char& name, ChessBoard& board)
{

	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;
	if (iswhite) {
		if (board.chessboard[nextrp][nextcp]!=nullptr&&board.chessboard[nextrp][nextcp]->iswhite == iswhite || name != 'n')
			return false;
		else
			return true;
	}
	else {
		if (board.chessboard[nextrp][nextcp]->iswhite == iswhite || name != 'N')
			return false;
		else
			return true;
	}
}

void Knight::Move(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const
{
	board.chessboard[nextrp][nextcp] = std::make_unique<Knight>(nextrp, nextcp, name, iswhite);
	board.chessboard[rp][cp].reset();
	board.chessboard[rp][cp] = nullptr;
}

void Knight::Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const
{
	board.chessboard[nextrp][nextcp].reset();
	board.chessboard[nextrp][nextcp] = nullptr;
	board.chessboard[nextrp][nextcp] = std::make_unique<Knight>(nextrp, nextcp, name, iswhite);
	board.chessboard[rp][cp].reset();
	board.chessboard[rp][cp] = nullptr;
}


