#include "Chess.h"
#include "ChessBoard.h"
#include <iostream>
#include <memory>

using namespace std;

bool Bishop::IsMove(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board)
{
	int x = 0;
	if (nextcp == cp && nextrp == rp)
		return false;
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;
	if (rp < nextrp && cp < nextcp) {
		for (int i = rp; i <= nextrp; i++) {
			if (board.chessboard[i+1][cp+x+1] != nullptr) {
				return false;
			}
			x++;
		}
		return true;
	}
	if (rp > nextrp && cp < nextcp) {
		for (int i = nextrp; i < rp; i++) {
			if (board.chessboard[i][nextcp-x] != nullptr) {
				return false;
			}
			x++;
		}
		return true;
	}
	if (rp > nextrp && cp > nextcp) {
		for (int i = nextrp; i < rp; i++) {
			if (board.chessboard[i][nextcp + x] != nullptr) {
				return false;
			}
			x++;
		}
		return true;
	}
	if (rp<nextrp && cp>nextcp) {
		for (int i = rp; i < nextrp; i++) {
			if (board.chessboard[i+1][cp -x-1] != nullptr) {
				return false;
			}
			x++;
		}
		return true;
	}
	return false;
}

bool Bishop::CanMove(int& nextrp, int& nextcp, int& rp, int& cp)
{
	if (nextcp == cp && nextrp == rp)
		return false;
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;

	if (rp < nextrp && cp < nextcp) {
			if (nextrp - rp != nextcp - cp) {
				return false;
			}
		return true;
	}
	if (rp > nextrp && cp < nextcp) {
			if (rp-nextrp!=nextcp-cp) {
				return false;
			}
		return true;
	}
	if (rp > nextrp && cp > nextcp) {
			if (rp-nextrp!=cp-nextcp) {
				return false;
			}
		return true;
	}
	if (rp<nextrp && cp>nextcp) {
			if (nextrp-rp!=cp-nextcp) {
				return false;
			}
		return true;
	}
	return false;
}

bool Bishop::CanHit(int& nextrp, int& nextcp, int& rp, int& cp,bool& iswh, ChessBoard& board)
{
	if (nextcp == cp && nextrp == rp)
		return false;
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;
	int x = 0;
	if (rp < nextrp && cp < nextcp) {
		for (int i = rp+1; i < nextrp; i++) {
			if (board.chessboard[i][cp + x + 1] != nullptr) {
				return false;
			}
			x++;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswhite)
			return false;
		return true;

	}
	if (rp > nextrp && cp < nextcp) {
		for (int i = nextrp+1; i < rp; i++) {
			if (board.chessboard[i][nextcp - x-1] != nullptr) {
				return false;
			}
			x++;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswhite)
			return false;
		return true;
	}
	if (rp > nextrp && cp > nextcp) {
		for (int i = nextrp+1; i < rp; i++) {
			if (board.chessboard[i][nextcp + x+1] != nullptr) {
				return false;
			}
			x++;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswhite)
			return false;
		return true;
	}
	if (rp<nextrp && cp>nextcp) {
		for (int i = rp+1; i < nextrp; i++) {
			if (board.chessboard[i][cp - x-1] != nullptr) {
				return false;
			}
			x++;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswhite)
			return false;
		return true;
	}
	return false;
}


void Bishop::Move(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board,char &name,bool &iswhite) const
{
	board.chessboard[nextrp][nextcp] = std::make_unique<Bishop>(nextrp, nextcp, name, iswhite);
	board.chessboard[rp][cp].reset();
	board.chessboard[rp][cp] = nullptr;
}

void Bishop::Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const
{
	board.chessboard[nextrp][nextcp].reset();
	board.chessboard[nextrp][nextcp] = nullptr;
	board.chessboard[nextrp][nextcp] = std::make_unique<Bishop>(nextrp, nextcp, name, iswhite);
	board.chessboard[rp][cp].reset();
	board.chessboard[rp][cp] = nullptr;
}
