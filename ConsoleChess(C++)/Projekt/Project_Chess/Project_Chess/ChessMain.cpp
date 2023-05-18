#include <iostream>
#include <utility>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "ChessBoard.h"
#include "Chess.h"
#include"Chesstranslator.h"

using namespace std;

int main() {
	{
		bool iswhite = true;
		Instruction();
		system("Pause");
		system("cls");
		Game(iswhite);
	}
	 _CrtDumpMemoryLeaks();

}