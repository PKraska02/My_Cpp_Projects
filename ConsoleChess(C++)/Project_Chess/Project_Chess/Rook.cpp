#include "Chess.h"
#include "ChessBoard.h"
#include <iostream>
#include <vector>
#include <memory>

bool Rook::LongRosch(bool& iswht, ChessBoard& b)
{
	//For white pieces
	if (iswht) {
		if (b.chessboard[0][4]->iskingmoved == false && b.chessboard[0][0]->figurename == 'r' && b.chessboard[0][0]->isrookmove==false && b.chessboard[0][4]->figurename == 'k') {
			for (int i = 1; i < 4; i++) {
				if (b.chessboard[0][i] != nullptr) {
					return false;
				}
			}
			b.chessboard[0][4] = nullptr;
			b.chessboard[0][0] = nullptr;
			b.chessboard[0][2] = std::make_unique<King>(0, 2, 'k', true);
			b.chessboard[0][3] = std::make_unique<Rook>(0, 3, 'r', true);
			b.chessboard[0][2]->iskingmoved = true;
			b.chessboard[0][3]->isrookmove = true;
			return true;
		}
	}
	else {
		if (b.chessboard[7][4]->iskingmoved == false && b.chessboard[7][0]->figurename == 'R' && b.chessboard[7][0]->isrookmove==false && b.chessboard[7][4]->figurename == 'K') {
			for (int i = 1; i < 4; i++) {
				if (b.chessboard[7][i] != nullptr) {
					return false;
				}
			}
			b.chessboard[7][4] = nullptr;
			b.chessboard[7][0] = nullptr;
			b.chessboard[7][2] = std::make_unique<King>(7, 2, 'K', false);
			b.chessboard[7][3] = std::make_unique<Rook>(7, 3, 'R', false);
			b.chessboard[7][2]->iskingmoved = true;
			b.chessboard[7][3]->isrookmove = true;
			return true;
		}

	}
}

bool Rook::ShortRosch(bool& iswht, ChessBoard& b)
{

	if (iswht) {
		if (b.chessboard[0][4]->iskingmoved == false && b.chessboard[0][7]->figurename == 'r' && b.chessboard[0][7]->isrookmove==false && b.chessboard[0][4]->figurename == 'k') {
			for (int i = 5; i < 7; i++) {
				if (b.chessboard[0][i] != nullptr) {
					return false;
				}
			}
			b.chessboard[0][4] = nullptr;
			b.chessboard[0][7] = nullptr;
			b.chessboard[0][6] = std::make_unique<King>(0,6,'k',true);
			b.chessboard[0][5] = std::make_unique<Rook>(0, 5, 'r', true);
			b.chessboard[0][6]->iskingmoved = true;
			b.chessboard[0][5]->isrookmove = true;
			return true;
		}
	}
		else {
			if (b.chessboard[7][4]->iskingmoved == false && b.chessboard[7][7]->figurename == 'R' && b.chessboard[7][7]->isrookmove==false && b.chessboard[7][4]->figurename == 'K') {
				for (int i = 5; i < 7; i++) {
					if (b.chessboard[7][i] != nullptr) {
						return false;
					}
				}
				b.chessboard[7][4] = nullptr;
				b.chessboard[7][7] = nullptr;
				b.chessboard[7][6] = std::make_unique<King>(7, 6, 'K', false);
				b.chessboard[7][5] = std::make_unique<Rook>(7, 5, 'R', false);
				b.chessboard[7][6]->iskingmoved = true;
				b.chessboard[7][5]->isrookmove = true;
				return true;
			}

		}
}

bool Rook::CanMove(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board)
{
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;
	if ((nextrp ==rp && nextcp != cp)||(nextrp!=rp&&nextcp==cp))
		return true;
	return false;
}

bool Rook::IsMove(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board)
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
			if (board.chessboard[rp][i+1] != nullptr)
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
			if (board.chessboard[i+1][cp] != nullptr)
				return false;
		}
		return true;
	}
	return false;
}

bool Rook::IsHit(int& nextrp, int& nextcp, int& rp, int& cp,bool &iswhite, ChessBoard& board)
{
	if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
		return false;
	if (nextcp == cp && nextrp == rp)
		return false;
	if (nextrp == rp && cp > nextcp) {
		for (int i = nextcp+1; i < cp; i++) {
			if (board.chessboard[rp][i] != nullptr)
				return false;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswhite)
			return false;
		return true;
	}
	if (nextrp == rp && cp < nextcp) {
		for (int i = cp+1; i < nextcp; i++) {
			if (board.chessboard[rp][i] != nullptr)
				return false;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswhite)
			return false;
		return true;
	}
	if (nextrp < rp && cp == nextcp) {
		for (int i = nextrp+1; i < rp; i++) {
			if (board.chessboard[i][cp] != nullptr)
				return false;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswhite)
			return false;
		return true;
	}
	if (nextrp > rp && cp == nextcp) {
		for (int i = rp+1; i < nextrp; i++) {
			if (board.chessboard[i][cp] != nullptr)
				return false;
		}
		if (board.chessboard[nextrp][nextcp]->iswhite == iswhite)
			return false;
		return true;
	}
	return false;
}

void Rook::Move(int& nextrp, int& nextcp, int& rp, int& cp,ChessBoard &board, char& name, bool& iswhite) const
{
	board.chessboard[nextrp][nextcp] = std::make_unique<Rook>(nextrp, nextcp, name, iswhite);
	if (board.chessboard[nextrp][nextcp]->iswhite == true) {
		if ((board.chessboard[rp][cp]->rowposition != 0 || board.chessboard[rp][cp]->columnposition != 0)
			|| (board.chessboard[rp][cp]->rowposition != 0 || board.chessboard[rp][cp]->columnposition != 8 )) {
			board.chessboard[board.chessboard[rp][cp]->rowposition][board.chessboard[rp][cp]->columnposition]->isrookmove = true;
		}
	}
	else
	{
		if ((board.chessboard[rp][cp]->rowposition != 7 || board.chessboard[rp][cp]->columnposition != 0)
			|| (board.chessboard[rp][cp]->rowposition != 7 || board.chessboard[rp][cp]->columnposition != 8)) {
			board.chessboard[board.chessboard[rp][cp]->rowposition][board.chessboard[rp][cp]->columnposition]->isrookmove = true;
		}
	}
	board.chessboard[rp][cp].reset();
	board.chessboard[rp][cp] = nullptr;
}

void Rook::Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const
{
	board.chessboard[nextrp][nextcp].reset();
	board.chessboard[nextrp][nextcp] = nullptr;
	board.chessboard[nextrp][nextcp] = std::make_unique<Rook>(nextrp, nextcp, name, iswhite);
	if (board.chessboard[nextrp][nextcp]->iswhite == true) {
		if ((board.chessboard[rp][cp]->rowposition != 0 || board.chessboard[rp][cp]->columnposition != 0)
			|| (board.chessboard[rp][cp]->rowposition != 0 || board.chessboard[rp][cp]->columnposition != 8)) {
			board.chessboard[board.chessboard[rp][cp]->rowposition][board.chessboard[rp][cp]->columnposition]->isrookmove = true;
		}
	}
	else
	{
		if ((board.chessboard[rp][cp]->rowposition != 7 || board.chessboard[rp][cp]->columnposition != 0)
			|| (board.chessboard[rp][cp]->rowposition != 7 || board.chessboard[rp][cp]->columnposition != 8)) {
			board.chessboard[board.chessboard[rp][cp]->rowposition][board.chessboard[rp][cp]->columnposition]->isrookmove = true;
		}
	}
	board.chessboard[rp][cp].reset();
	board.chessboard[rp][cp] = nullptr;
}
