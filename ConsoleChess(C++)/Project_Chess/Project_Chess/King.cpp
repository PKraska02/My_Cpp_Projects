#include "Chess.h"
#include "ChessBoard.h"
#include <iostream>
#include <memory>


bool King::CanMove(int& nextrp, int& nextcp, int& rp, int& cp)
{
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;
	if ((nextrp == rp && nextcp - cp == 1) ||
		(rp - nextrp == 1 && nextcp - cp == 1) ||
		(rp - nextrp == 1 && cp == nextcp) ||
		(rp - nextrp == 1 && cp - nextcp == 1) ||
		(rp == nextrp && cp - nextcp == 1) ||
		(nextrp - rp == 1 && cp - nextcp == 1) ||
		(nextrp - rp == 1 && nextcp == cp)
		) 
	{
		return true;
	}
	return false;
}

bool King::CanHit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board,bool &iswhite)
{
	if (board.chessboard[nextrp][nextcp]->iswhite == iswhite) {
		return false;
	}
	return true;
}

bool King::IsMove(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board)
{
	if (board.chessboard[nextrp][nextcp] != nullptr) {
		return false;
	}
	return true;
}


bool King::IsCheck(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board)
{

	return true;
}

bool King::IsCheckMate(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board)
{
	return false;
}

void King::Move(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board,char& name, bool& iswhite) const
{
	board.chessboard[nextrp][nextcp] = std::make_unique<King>(nextrp, nextcp, name, iswhite);
	if (board.chessboard[nextrp][nextcp]->iswhite == true) {
		if (board.chessboard[rp][cp]->rowposition != 0 || board.chessboard[rp][cp]->columnposition != 4) {
			board.chessboard[board.chessboard[rp][cp]->rowposition][board.chessboard[rp][cp]->columnposition]->iskingmoved = true;
		}
	}
	else
	{
		if (board.chessboard[rp][cp]->rowposition != 7 || board.chessboard[rp][cp]->columnposition != 4) {
			board.chessboard[board.chessboard[rp][cp]->rowposition][board.chessboard[rp][cp]->columnposition]->iskingmoved = true;
		}

	}
	board.chessboard[rp][cp].reset();
	board.chessboard[rp][cp] = nullptr;
}

void King::Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const
{
	board.chessboard[nextrp][nextcp].reset();
	board.chessboard[nextrp][nextcp] = nullptr;
	board.chessboard[nextrp][nextcp] = std::make_unique<King>(nextrp, nextcp, name, iswhite);
	if (board.chessboard[nextrp][nextcp]->iswhite == true) {
		if (board.chessboard[rp][cp]->rowposition != 0 || board.chessboard[rp][cp]->columnposition != 4) {
			board.chessboard[board.chessboard[rp][cp]->rowposition][board.chessboard[rp][cp]->columnposition]->iskingmoved = true;
		}
	}
	else
	{
		if (board.chessboard[rp][cp]->rowposition != 7 || board.chessboard[rp][cp]->columnposition != 4) {
			board.chessboard[board.chessboard[rp][cp]->rowposition][board.chessboard[rp][cp]->columnposition]->iskingmoved = true;
		}

	}
	board.chessboard[rp][cp].reset();
	board.chessboard[rp][cp] = nullptr;
}
