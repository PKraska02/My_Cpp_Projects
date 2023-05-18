#include "Chess.h"
#include "ChessBoard.h"
#include <iostream>
#include <memory>

bool Queen::IsMovediagonal(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board)
{
	int x = 0;
	if (nextcp == cp && nextrp == rp)
		return false;
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;
	if (rp < nextrp && cp < nextcp) {
		for (int i = rp; i <= nextrp; i++) {
			if (board.chessboard[i + 1][cp + x + 1] != nullptr) {
				return false;
			}
			x++;
		}
		return true;
	}
	if (rp > nextrp && cp < nextcp) {
		for (int i = nextrp; i < rp; i++) {
			if (board.chessboard[i][nextcp - x] != nullptr) {
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
		for (int i = rp; i <= nextrp; i++) {
			if (board.chessboard[i + 1][cp - x-1] != nullptr) {
				return false;
			}
			x++;
		}
		return true;
	}
	return false;
}

bool Queen::CanMovediagonal(int& nextrp, int& nextcp, int& rp, int& cp)
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
			if (rp - nextrp != nextcp - cp) {
				return false;
			}
		return true;
	}
	if (rp > nextrp && cp > nextcp) {
			if (rp - nextrp != cp - nextcp) {
				return false;
			}
		return true;
	}
	if (rp<nextrp && cp>nextcp) {
			if (nextrp - rp != cp - nextcp) {
				return false;
			}
		return true;
	}
}

bool Queen::CanHitdiagonal(int& nextrp, int& nextcp, int& rp, int& cp, bool& iswh, ChessBoard& board)
{
	if (nextcp == cp && nextrp == rp)
		return false;
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;
	int x = 0;
	if (rp < nextrp && cp < nextcp) {
		for (int i = rp + 1; i < nextrp; i++) {
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
		for (int i = nextrp + 1; i < rp; i++) {
			if (board.chessboard[i][nextcp - x - 1] != nullptr) {
				return false;
			}
			x++;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswhite)
			return false;
		return true;
	}
	if (rp > nextrp && cp > nextcp) {
		for (int i = nextrp + 1; i < rp; i++) {
			if (board.chessboard[i][nextcp + x + 1] != nullptr) {
				return false;
			}
			x++;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswhite)
			return false;
		return true;
	}
	if (rp<nextrp && cp>nextcp) {
		for (int i = rp + 1; i < nextrp; i++) {
			if (board.chessboard[i][cp - x - 1] != nullptr) {
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
//
bool Queen::CanMoveStraight(int& nextrp, int& nextcp, int& rp, int& cp)
{
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;
	if ((nextrp == rp && nextcp != cp) || (nextrp != rp && nextcp == cp))
		return true;
	return false;

}

bool Queen::IsMoveStraight(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board)
{
	if (nextcp == cp && nextrp == rp)
		return false;
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;
	if (nextrp == rp && cp > nextcp) {
		for (int i = nextcp; i < cp; i++) {
			if (board.chessboard[rp][i] != nullptr)
				return false;
		}
		return true;
	}
	if (nextrp == rp && cp < nextcp) {
		for (int i = cp; i < nextcp; i++) {
			if (board.chessboard[rp][i + 1] != nullptr)
				return false;
		}
		return true;
	}
	if (nextrp < rp && cp == nextcp) {
		for (int i = nextrp; i < rp; i++) {
			if (board.chessboard[i][cp] != nullptr)
				return false;
		}
		return true;
	}
	if (nextrp > rp && cp == nextcp) {
		for (int i = rp; i < nextrp; i++) {
			if (board.chessboard[i + 1][cp] != nullptr)
				return false;
		}
		return true;
	}
	return false;
}

bool Queen::IsHitStraight(int& nextrp, int& nextcp, int& rp, int& cp, bool& iswh, ChessBoard& board)
{
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;
	if (nextcp == cp && nextrp == rp)
		return false;
	if (nextrp == rp && cp > nextcp) {
		for (int i = nextcp + 1; i < cp; i++) {
			if (board.chessboard[rp][i] != nullptr)
				return false;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswh)
			return false;
		return true;
	}
	if (nextrp == rp && cp < nextcp) {
		for (int i = cp + 1; i < nextcp; i++) {
			if (board.chessboard[rp][i] != nullptr)
				return false;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswh)
			return false;
		return true;
	}
	if (nextrp < rp && cp == nextcp) {
		for (int i = nextrp + 1; i < rp; i++) {
			if (board.chessboard[i][cp] != nullptr)
				return false;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswh)
			return false;
		return true;
	}
	if (nextrp > rp && cp == nextcp) {
		for (int i = rp + 1; i < nextrp; i++) {
			if (board.chessboard[i][cp] != nullptr)
				return false;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswh)
			return false;
		return true;
	}
	return false;
}
void Queen::Move(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const
{
	board.chessboard[rp][cp].reset();
	board.chessboard[nextrp][nextcp] = std::make_unique<Queen>(nextrp, nextcp, name, iswhite);
	board.chessboard[rp][cp] = nullptr;
}

void Queen::Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const
{
	board.chessboard[nextrp][nextcp] = nullptr;
	board.chessboard[nextrp][nextcp].reset();
	board.chessboard[nextrp][nextcp] = std::make_unique<Queen>(nextrp, nextcp, name, iswhite);
	board.chessboard[rp][cp].reset();
	board.chessboard[rp][cp] = nullptr;
}
