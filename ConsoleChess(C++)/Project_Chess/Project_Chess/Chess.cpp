#include <iostream>
#include "ChessBoard.h"
#include "Chess.h"
#include "Chesstranslator.h"
#include <memory>

using namespace std;

PlayerData PreGameInformation() {
	PlayerData pd;
	std::string temp;
	cout << "Important message!\n";
	cout << "Player1 play as white, Player2 play as black\n";
	cout << "Write your nickname Player1:\n";
	cin >> temp;
	pd.playerdata.push_back(temp);
	temp = "";
	cout << "Write your nickcname Player2:\n";
	cin >> temp;
	pd.playerdata.push_back(temp);
	temp = "";
	cout << "Press Enter to start a game!\n";
	std::cout << pd.playerdata[0];
	system("cls");
	return pd;
}
void Instruction()
{
	std::cout << "Before the game read the instructions:\n";
	std::cout << "How to move?\n Example of the move: nb0d2 it means that knight from b0 goes to d2 (if he can move on this place) \n";
	std::cout << "Very Important!!  Player playing with white pieces to represent type of figure MUST USE lowercase letters, and player playing with black pieces MUST USE uppercase letters to represent type of figure.\n";
	std::cout << "If you want use LongRosch/ShortRosch just type LongRosch/ShortRosch\n";
	std::cout << "If you want give up just type resign\n";
}
void ChessBoardGenerator(ChessBoard& board) {
	cout << "   __A___B___C___D___E___F___G___H__\n";
	for (int i = 0; i < 8; i++) {
		cout << "    ________________________________ \n";
		cout << i << " ";
		for (int j = 0; j < 8; j++) {
			if (board.chessboard[i][j] == nullptr)
				cout << " | " << ' ';
			else
				cout << " | " << board.chessboard[i][j]->figurename;
		}
		cout << " | " << i << " \n";

	}
	cout << "   __________________________________\n";
	cout << "   __A___B___C___D___E___F___G___H__ \n";
}
void ReverseBoardGenerator(ChessBoard& board) {
	cout << "   __A___B___C___D___E___F___G___H__ \n";
	for (int i = 0; i < 8; i++) {
		cout << "    ________________________________ \n";
		cout << i << " ";
		for (int j = 0; j < 8; j++) {
			if (board.chessboard[i][j] == nullptr)
				cout << " | " << ' ';
			else
				cout << " | " << board.chessboard[i][j]->figurename;
		}
		cout << " | " << i << " \n";

	}
	cout << "   __________________________________\n";
	cout << "   __A___B___C___D___E___F___G___H__ \n";

}


void Moves(int& nextrp, int& nextcp, int& rp, int& cp, Figure* ptr, ChessBoard& board,char &name,bool &iswhite)
{
	ptr->Move(nextrp,nextcp, rp, cp, board, name, iswhite);
}

void Hits(int& nextrp, int& nextcp, int& rp, int& cp, Figure* ptr, ChessBoard& board, char& name, bool& iswhite)
{
	ptr->Hit(nextrp, nextcp, rp, cp, board, name, iswhite);
}

bool SpecialCommend(std::string& tpos, bool& iswh, bool& x, PlayerData pd, ChessBoard& board)
{
	Rook R(0, 0, 'r', true);
	std::string t;
	for (int i = 0; i < tpos.length(); i++) {
		t.push_back(tolower(tpos[i]));
	}
	if (t == "resign") {
		x = false;
		if (iswh) {
			std::cout << pd.playerdata[0] << " WON! \n";
			system("pause");
		}
		else
		{
			std::cout << pd.playerdata[1] << " WON! \n";
			system("pause");
		}
		return true;
	}
	if (t == "longrosch") {
		R.LongRosch(iswh,board);
		if (iswh) {
			iswh = false;
		}
		else
		{
			iswh = true;
		}
		return true;
	}
	if (t == "shortrosch") {
		R.ShortRosch(iswh,board);
		if (iswh) {
			iswh = false;
		}
		else
		{
			iswh = true;
		}
		return true;
	}
	t = "";
	return false;

}
void Game(bool& iswhite) {
	std::string tpos;
	ChessBoard chessboard;
	Moveparameters mp;
	Figure* ptr;
	PlayerData pd = PreGameInformation();
	bool x = true;
	while (x) {
		if (iswhite) {
			ReverseBoardGenerator(chessboard);
			while (true) {
				std::cout << "Type your move: \n";
				cin >> tpos;
				if (SpecialCommend(tpos, iswhite, x,pd,chessboard)) {
					break;
				}
				if (Splitdeclaratedmove(tpos,mp)) {
					Covertlettertonumberposition(mp);
					char c = mp.figuretype;
					//std::cout << c;
					if (c == 'p') {
						Pawn p(mp.numberstartposition, mp.convertnamestartposition, mp.figuretype, iswhite);
						ptr = &p;
						if (p.IsfirstMove(iswhite, mp.numberstartposition ,mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition, chessboard)) {
							Moves(mp.numbernextposition,mp.convertnamenextposition,mp.numberstartposition,mp.convertnamestartposition,ptr,chessboard, c, iswhite);
							iswhite = false;
							break;
						}
						if (p.IsMove(mp.numberstartposition, mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition, iswhite, chessboard)) {
							Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard,c,iswhite);
							iswhite = false;
							break;
						}
						if (p.IsHit(mp.numberstartposition, mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition, iswhite, chessboard)){
							Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition,ptr, chessboard, c, iswhite);
							iswhite = false;
							break;
						}
						if (p.Promotion(mp.convertnamenextposition, mp.numbernextposition, chessboard,iswhite)) {
							iswhite = false;
							break;
						}
						std::cout << "Incorrect move...Try again \n";
					}
					if (c == 'n') {
						Knight n(mp.convertnamestartposition, mp.numberstartposition, mp.figuretype, iswhite);
						ptr = &n;
						if (!n.IsGoodMove(iswhite, mp.numberstartposition, mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition)) {
							std::cout << "Incorrect move...Try again \n";
						}
						else
						{
							if (n.CanMove(iswhite, mp.numberstartposition, mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition,c, chessboard)) {
								Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = false;
								break;
							}
							if (n.CanHit(iswhite, mp.numberstartposition, mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition,c, chessboard)) {
								Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = false;
								break;
							}

						}
					}
					if (c == 'b') {
						Bishop b(mp.convertnamestartposition, mp.numberstartposition, mp.figuretype, iswhite);
						ptr = &b;
						if (!b.CanMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition)) {
							std::cout << "Incorrect move...Try again \n";
						}
						else
						{
							if (b.IsMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
								Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = false;
								break;
							}
							if (b.CanHit(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, iswhite, chessboard)) {
								Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = false;
								break;
							}

						}
					}
					if (c == 'r') {
						Rook r(mp.convertnamestartposition, mp.numberstartposition, mp.figuretype, iswhite);
						ptr = &r;
						if (!r.CanMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
							std::cout << " Incorrect move... Try again \n";
						}
						else
						{
							if (r.IsMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
								Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = false;
								break;
							}
							if (r.IsHit(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, iswhite, chessboard)) {
								Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = false;
								break;
							}
						}
					}
					if (c == 'q') {
						Queen q(mp.convertnamestartposition, mp.numberstartposition, mp.figuretype, iswhite);
						ptr = &q;
						if (q.CanMoveStraight(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition)) {
							if (q.IsMoveStraight(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
								Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = false;
								break;
							}
							if (q.IsHitStraight(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition,iswhite, chessboard)) {
								Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = false;
								break;
							}
						}
						else {
							if (q.CanMovediagonal(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition)) {
								if (q.IsMovediagonal(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
									Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
									iswhite = false;
									break;
								}
								if (q.CanHitdiagonal(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition,iswhite, chessboard)) {
									Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard,c,iswhite);
									iswhite = false;
									break;
								}
							}
						}

					}
					if (c == 'k') {
						King k(mp.convertnamestartposition, mp.numberstartposition, mp.figuretype, iswhite);
						ptr = &k;
						if (!k.CanMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition)) {
							std::cout << " Incorrect move... Try again \n";
						}
						else
						{
							if (k.IsMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
								Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = false;
								break;
							}
							if (k.CanHit(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard,iswhite)) {
								Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = false;
								break;
							}
						}
					}
					//iswhite = false;
				}
				else
				{
				std::cout << "Figure you choose does not exist...\n";
				}
			}
			system("cls");
		}
		else
		{
			ChessBoardGenerator(chessboard);
			while (true) {
				std::cout << "Type your move: \n";
				cin >> tpos;
				if (SpecialCommend(tpos, iswhite, x,pd,chessboard)) {
					break;
				}
				if (Splitdeclaratedmove(tpos,mp)) {
					Covertlettertonumberposition(mp);
					char c = mp.figuretype;
					//std::cout << c;
					if (c == 'P') {
						Pawn P(mp.convertnamestartposition, mp.numberstartposition, mp.figuretype, iswhite);
						ptr = &P;
						if (P.IsfirstMove(iswhite, mp.numberstartposition, mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition, chessboard)) {
							Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
							iswhite = true;
							break;
						}
						if (P.IsMove(mp.numberstartposition, mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition, iswhite, chessboard)) {
							Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
							iswhite = true;
							break;
						}
						if (P.IsHit(mp.numberstartposition, mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition, iswhite, chessboard)) {
							Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
							iswhite = true;
							break;
						}
						if (P.Promotion(mp.convertnamenextposition, mp.numbernextposition,chessboard,iswhite)) {
							iswhite = true;
							break;
						}
						std::cout << "Incorrect move...Try again \n";
					}
					if (c == 'N') {
						Knight N(mp.convertnamestartposition, mp.numberstartposition, mp.figuretype, iswhite);
						ptr = &N;
						if (!N.IsGoodMove(iswhite, mp.numberstartposition, mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition)) {
							std::cout << "Incorrect move...Try again \n";
						}
						else
						{
							if (N.CanMove(iswhite, mp.numberstartposition, mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition,c, chessboard)) {
								Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = true;
								break;
							}
							if (N.CanHit(iswhite, mp.numberstartposition, mp.convertnamestartposition, mp.numbernextposition, mp.convertnamenextposition,c, chessboard)) {
								Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = true;
								break;
							}

						}
					}
					if (c == 'B') {
						Bishop B(mp.convertnamestartposition, mp.numberstartposition, mp.figuretype, iswhite);
						ptr = &B;
						if (!B.CanMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition)) {
							std::cout << "Incorrect move...Try again \n";
						}
						else
						{
							if (B.IsMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
								Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = true;
								break;
							}
							if (B.CanHit(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, iswhite, chessboard)) {
								Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = true;
								break;
							}

						}
					}
					if (c == 'R') {
						Rook R(mp.convertnamestartposition, mp.numberstartposition, mp.figuretype, iswhite);
						ptr = &R;
						if (!R.CanMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
							std::cout << " Incorrect move... Try again \n";
						}
						else
						{
							if (R.IsMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
								Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = true;
								break;
							}
							if (R.IsHit(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, iswhite, chessboard)) {
								Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = true;
								break;
							}
						}
					}
					if (c == 'Q') {
						Queen Q(mp.convertnamestartposition, mp.numberstartposition, mp.figuretype, iswhite);
						ptr = &Q;
						if (Q.CanMoveStraight(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition)) {
							if (Q.IsMoveStraight(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
								Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = true;
								break;
							}
							if (Q.IsHitStraight(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition,iswhite, chessboard)) {
								Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = true;
								break;
							}
						}
						else {
							if (Q.CanMovediagonal(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition)) {
								if (Q.IsMovediagonal(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
									Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
									iswhite = true;
									break;
								}
								if (Q.CanHitdiagonal(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition,iswhite, chessboard)) {
									Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
									iswhite = true;
									break;
								}
							}
						}

					}
					if (c == 'K') {
						King K(mp.convertnamestartposition, mp.numberstartposition, mp.figuretype, iswhite);
						ptr = &K;
						if (!K.CanMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition)) {
							std::cout << " Incorrect move... Try again \n";
						}
						else
						{
							if (K.IsMove(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard)) {
								Moves(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = true;
								break;
							}
							if (K.CanHit(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, chessboard,iswhite)) {
								Hits(mp.numbernextposition, mp.convertnamenextposition, mp.numberstartposition, mp.convertnamestartposition, ptr, chessboard, c, iswhite);
								iswhite = true;
								break;
							}
						}
					}
					//iswhite = true;

				}
				else
				{
				std::cout << "Figure you choose does not exist...\n";
				}
			}
		}
		system("cls");
	}
}

