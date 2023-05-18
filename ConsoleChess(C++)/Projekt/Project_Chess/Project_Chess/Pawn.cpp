#include <iostream>
#include "Chess.h"
#include "ChessBoard.h"
#include <memory>

using namespace std;
	bool Pawn::IsfirstMove(bool iswhite, int& rp, int& cp, int& nextrp, int& nextcp, ChessBoard& board) {
		if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
			return false;
		if (iswhite == true) {
			if (board.chessboard[nextrp][nextcp] == nullptr && board.chessboard[nextrp - 1][nextcp] == nullptr && (nextrp == rp + 2) && (nextcp == cp))
				return true;
			else
				return false;
		}
		else {
			if (board.chessboard[nextrp][nextcp] == nullptr && board.chessboard[nextrp+1][nextcp] == nullptr&& (nextrp == rp - 2) && (nextcp == cp))
				return true;
			else
				return false;

		}
	}
	bool Pawn::IsMove(int& rp, int& cp, int& nextrp, int& nextcp, bool &iswhite, ChessBoard& board) {
		if (nextrp>8 || nextrp<-1 || nextcp>8 || nextrp<-1)
			return false;
		if (iswhite == true) {
			if (board.chessboard[nextrp][nextcp] == nullptr && (nextrp == rp + 1) && (nextcp == cp))
				return true;
			else
				return false;
		}
		else {
			if (board.chessboard[nextrp][nextcp] == nullptr && (nextrp == rp - 1) && (nextcp == cp))
				return true;
			else
				return false;

		}
	}
	bool Pawn::IsHit(int& rp, int& cp, int& nextrp, int& nextcp, bool& iswhite, ChessBoard& board) {
		if (nextrp > 8 || nextrp < -1 || nextcp>8 || nextrp < -1)
			return false;
		if (iswhite == true) {
			if (nextrp == rp + 1 && ((nextcp==cp+1)||(nextcp==cp-1))) {
				if (board.chessboard[nextrp][nextcp] == nullptr || board.chessboard[nextrp][nextcp]->iswhite == iswhite) {
					return false;
				}
				return true;
			}
		}
		else {
				if (nextrp == rp - 1 && ((nextcp == cp + 1) || (nextcp == cp - 1))) {
					if (board.chessboard[nextrp][nextcp] == nullptr || board.chessboard[nextrp][nextcp]->iswhite == iswhite) {
						return false;
					}
						return true;
					}
		}
		return true;
	}
	bool Pawn::EnPassant(int& rp, int& cp, bool &iswhite, ChessBoard& board) {
		return true;
	}
	bool Pawn::Promotion(int& nextrp, int& nextcp, ChessBoard& board,bool &iswh)
	{
		if (iswh) {
			if (nextrp == 7) {
				board.chessboard[nextrp][nextcp] = nullptr;
				board.chessboard[nextrp][nextcp] = std::make_unique<Queen>(nextrp,nextcp,'q',true);
			}
		}
		else
		{
			if (nextrp == 0) {
				board.chessboard[nextrp][nextcp] = nullptr;
				board.chessboard[nextrp][nextcp] = std::make_unique<Queen>(nextrp, nextcp, 'Q', false);
			}
		}
		return false;
	}
	void Pawn::Move(int& nextrp, int& nextcp, int& rp, int& cp,ChessBoard& board,char &name,bool &iswhite) const
	{
		board.chessboard[nextrp][nextcp] = std::make_unique<Pawn>(nextrp, nextcp, name, iswhite);
		board.chessboard[rp][cp].reset();
		board.chessboard[rp][cp]=nullptr;
	
		//std::cout << "To ja Pionek\n";
	}

	void Pawn::Hit(int& nextrp, int& nextcp,int& rp, int& cp,ChessBoard& board, char& name, bool& iswhite) const
	{
		board.chessboard[nextrp][nextcp].reset();
		board.chessboard[nextrp][nextcp] = nullptr;
		board.chessboard[nextrp][nextcp] = std::make_unique<Pawn>(nextrp, nextcp, name, iswhite);
		board.chessboard[rp][cp].reset();
		board.chessboard[rp][cp] = nullptr;
		//std::cout << "To ja Zbity Pionek\n";
	}



