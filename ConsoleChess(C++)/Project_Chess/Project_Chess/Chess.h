#pragma once
#include <iostream>
#include"ChessBoard.h"
class  ChessBoard;
struct PlayerData {
	std::vector<std::string>playerdata{};
};
PlayerData PreGameInformation();
bool SpecialCommend(std::string& tpos, bool& iswh, bool& x,PlayerData pd, ChessBoard& board);
void Instruction();

class Figure {
public:
	virtual void Move(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const = 0;
	virtual void Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const = 0;
	int rowposition;
	int columnposition;
	char figurename;
	bool iswhite;
	bool isrookmove = false;
	bool iskingattacked = false;
	bool iskingmoved = false;
	Figure(int rowposition ,int columnposition,char figurename,bool iswhite)
		:rowposition(rowposition),columnposition(columnposition),figurename(figurename),iswhite(iswhite) {};
	virtual ~Figure() {};
};
class Pawn :public Figure {
public:
	Pawn(int rp, int cp , char name, bool iswh) :Figure(rowposition, columnposition, figurename, iswhite) {
		this->rowposition = rp;
		this->columnposition = cp;
		this->figurename = name;
		this->iswhite = iswh;

	};
	bool IsfirstMove(bool iswhite, int& rp, int& cp, int& nextrp, int& nextcp, ChessBoard& board);
	bool IsMove(int &rp, int&cp, int& nextrp, int& nextcp,bool &iswhite, ChessBoard& board);
	bool IsHit(int& rp, int& cp, int& nextrp, int& nextcp, bool &iswhite, ChessBoard& board);
	bool EnPassant(int& rp, int& cp,bool &iswhite, ChessBoard& board);
	bool Promotion(int& nextrp, int& nextcp, ChessBoard& board, bool& iswh);
	virtual void Move(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;
	virtual void Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;
};
class Knight :public Figure {
public:
	Knight(int rp, int cp, char name, bool iswh) :Figure(rowposition, columnposition, figurename, iswhite) {
		this->rowposition = rp;
		this->columnposition = cp;
		this->figurename = name;
		this->iswhite = iswh;

	};
	bool IsGoodMove(bool iswhite, int& rp, int& cp, int& nextrp, int& nextcp);
	bool CanMove(bool iswhite, int& rp, int& cp, int& nextrp, int& nextcp, char& name, ChessBoard& board);
	bool CanHit(bool iswhite, int& rp, int& cp, int& nextrp, int& nextcp, char& name, ChessBoard& board);
	virtual void Move(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;
	virtual void Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;
};
class Bishop : public Figure {
public:
	Bishop(int rp, int cp, char name, bool iswh) :Figure(rowposition, columnposition, figurename, iswhite) {
		this->rowposition = rp;
		this->columnposition = cp;
		this->figurename = name;
		this->iswhite = iswh;

	};
	bool CanMove(int& nextrp, int& nextcp, int& rp, int& cp);
	bool IsMove(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board);
	bool CanHit(int& nextrp, int& nextcp, int& rp, int& cp,bool&ishwite, ChessBoard& board);
	virtual void Move(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;
	virtual void Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;
};
class Rook :public Figure {
public:
	Rook(int rp, int cp, char name, bool iswh) :Figure(rowposition, columnposition, figurename, iswhite) {
		this->rowposition = rp;
		this->columnposition = cp;
		this->figurename = name;
		this->iswhite = iswh;

	};
	bool LongRosch(bool& iswht, ChessBoard& b);
	bool ShortRosch(bool& iswht, ChessBoard& b);
	bool CanMove(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board);
	bool IsMove(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board);
	bool IsHit(int& nextrp, int& nextcp, int& rp, int& cp, bool& iswh, ChessBoard& board);
	virtual void Move(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;
	virtual void Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;
};
class Queen :public Figure {
public:
	Queen(int rp, int cp, char name, bool iswh) :Figure(rowposition, columnposition, figurename, iswhite) {
		this->rowposition = rp;
		this->columnposition = cp;
		this->figurename = name;
		this->iswhite = iswh;

	};
	bool IsMovediagonal(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board);
	bool CanMovediagonal(int& nextrp, int& nextcp, int& rp, int& cp);
	bool CanHitdiagonal(int& nextrp, int& nextcp, int& rp, int& cp,bool& iswh, ChessBoard& board);
	bool CanMoveStraight(int& nextrp, int& nextcp, int& rp, int& cp);
	bool IsMoveStraight(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board);
	bool IsHitStraight(int& nextrp, int& nextcp, int& rp, int& cp, bool& iswh, ChessBoard& board);
	virtual void Move(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;
	virtual void Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;

};
class King :public Figure {
public:
	King(int rp, int cp, char name, bool iswh) :Figure(rowposition, columnposition, figurename, iswhite) {
		this->rowposition = rp;
		this->columnposition = cp;
		this->figurename = name;
		this->iswhite = iswh;

	};
	bool CanMove(int& nextrp, int& nextcp, int& rp, int& cp);
	bool CanHit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board,bool &iswhite);
	bool IsMove(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board);
	bool IsCheck(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board);
	bool IsCheckMate(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board);
	virtual void Move(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;
	virtual void Hit(int& nextrp, int& nextcp, int& rp, int& cp, ChessBoard& board, char& name, bool& iswhite) const override;
};
void Moves(int& nextrp, int& nextcp, int& rp, int& cp,Figure *ptr, ChessBoard& board, char& name, bool& iswhite);
void Hits(int& nextrp, int& nextcp, int& rp, int& cp,Figure *ptr, ChessBoard& board, char& name, bool& iswhite);




