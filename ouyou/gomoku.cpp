// #include "pch.h"
#include <stdio.h>
#include <stdlib.h>

// マスの情報
#define EMPTY_SQUARE 0 // 空きマス
#define BLACK_STONE 1  // 黒い石
#define WHITE_STONE 2  // 白い石

//　手番
#define BLACK 1 // 黒の手番
#define WHITE 2 // 白の手番

// 五目並べの盤の大きさは15
#define BOARDSIZE 15

// COMと人間はプレイヤー
#define HUMAN 1 // 人間

// ゲームの結果
#define UNFINISHED 0 // まだ終わっていない
#define BLACK_WIN 1	 // 先手の勝ち
#define WHITE_WIN 2	 // 後手の勝ち
#define DRAW 3		 // 引き分け

// 先手と後手はCOMか人間かを管理する変数
int blackPlayer;
int whitePlayer;

int gomokuBoard[BOARDSIZE + 1][BOARDSIZE + 1]; // 五目並べの盤
int nextMoveX;								   // 次の手のx軸
int nextMoveY;								   // 次の手のy軸

// 関数のプロトタイプ
void makeBoardEmpty();
void showBoard();
int selectAI(int);
int playGomokuGame();
int fiveInRowCheck(int, int, int);
void getNextHumanMove();

int main()
{
	char c, userSelection;
	int gameResult;

	while (1)
	{
		// 盤を初期化
		makeBoardEmpty();

		// 初期局面を表示
		showBoard();

		// メーンメニュを表示
		printf("=============================================================\n");
		printf("This is a very weak Gomoku program made by Reijer Grimbergen.\n");
		printf("=============================================================\n");
		printf("Main menu:\n");
		printf("1) Play human against human\n");
		printf("Q) Quit program\n");
		printf("Please enter your selection: ");

		c = getchar();
		userSelection = c;
		while ((c = getchar()) != '\n')
			;

		switch (userSelection)
		{
		case '1':
			// COMは白の場合にプレイヤーを初期化
			blackPlayer = HUMAN;
			whitePlayer = HUMAN;
			// ゲームを最初から最後までやる
			gameResult = playGomokuGame();
			// 結果をユーザの伝える
			if (gameResult == BLACK_WIN)
				printf("\nBlack player wins.\n\n");
			else if (gameResult == WHITE_WIN)
				printf("\nWhite player wins.\n\n");
			else if (gameResult == DRAW)
				printf("\nThis game ended in a draw.\n\n");
			else
				printf("\nGame was not finished.\n\n");

			printf("Press any key to continue.\n");
			while ((c = getchar()) != '\n')
				;
			break;

		case 'Q':
			return 0;

		default:
			printf("Illegal input: Please select one of the menu options.\n");
			break;
		}
	}
	return 0;
}

// 盤の初期化：すべてのマスを空きマスにする
void makeBoardEmpty()
{
	int x, y;

	for (x = 1; x <= BOARDSIZE; x++)
		for (y = 1; y <= BOARDSIZE; y++)
			gomokuBoard[x][y] = EMPTY_SQUARE;
}

// 現在の局面を表示
void showBoard()
{
	int x, y;

	printf("   １ ２ ３ ４ ５ ６ ７ ８ ９ 10 11 12 13 14 15\n");
	for (y = 1; y <= BOARDSIZE; y++)
	{
		if (y < 10)
			printf(" %d", y);
		else
			printf("%d", y);
		for (x = 1; x <= BOARDSIZE; x++)
		{
			if (gomokuBoard[x][y] == BLACK_STONE)
				printf(" ●");
			else if (gomokuBoard[x][y] == WHITE_STONE)
				printf(" ○");
			else
				printf(" ＊");
		}
		printf("\n");
	}
}

// 人間対人間の対局．ゲームが終わるまで人間の手を獲得
int playGomokuGame()
{
	int gameResult = UNFINISHED;
	int toMove = BLACK;
	int moveCount = 1;

	nextMoveX = 0;
	nextMoveY = 0;
	// ゲームが終わるまでにプレイを続く
	while (gameResult == UNFINISHED)
	{
		// 人間の手番
		getNextHumanMove();
		printf("You played: %d) (%d,%d)\n", moveCount, nextMoveX, nextMoveY);

		// 石を盤に置く
		if (toMove == BLACK)
			gomokuBoard[nextMoveX][nextMoveY] = BLACK_STONE;
		else
			gomokuBoard[nextMoveX][nextMoveY] = WHITE_STONE;

		// 更新した局面を表示
		showBoard();

		// 手がさされたので手数を更新
		moveCount++;

		// 終了条件が満たしているかどうか
		if (fiveInRowCheck(nextMoveX, nextMoveY, toMove))
		{
			if (toMove == BLACK)
				gameResult = BLACK_WIN;
			else
				gameResult = WHITE_WIN;
			break;
		}
		else if (moveCount == (BOARDSIZE * BOARDSIZE)) // 盤はいっぱいになったかどうか
			gameResult = DRAW;

		// 手番を更新
		if (toMove == BLACK)
			toMove = WHITE;
		else
			toMove = BLACK;
		nextMoveX = 0;
		nextMoveY = 0;
	}

	return gameResult;
}

// 最後の手の情報を利用し、五目並べになったかどうかをチェック
int fiveInRowCheck(int lastX, int lastY, int color)
{
	int x, y;
	int connectNo = 1;

	// 横の五目並べチェック:(lastx, lasty)座標からcolorと同じ色の石の連結を右と左にあわせて数える
	if (lastX > 1)
	{
		for (x = lastX - 1; gomokuBoard[x][lastY] == color; x--)
		{
			connectNo++;
			if (x == 1)
				break;
		}
	}
	if (lastX < BOARDSIZE)
	{
		for (x = lastX + 1; gomokuBoard[x][lastY] == color; x++)
		{
			connectNo++;
			if (x == BOARDSIZE)
				break;
		}
	}
	if (connectNo >= 5)
		return 1; // 横の五目並べ見つけた

	// 縦の五目並べチェック:(lastx, lasty)座標からcolorと同じ色の石の連結を上と下にあわせて数える
	connectNo = 1;
	if (lastY > 1)
	{
		for (y = lastY - 1; gomokuBoard[lastX][y] == color; y--)
		{
			connectNo++;
			if (y == 1)
				break;
		}
	}
	if (lastY < BOARDSIZE)
	{
		for (y = lastY + 1; gomokuBoard[lastX][y] == color; y++)
		{
			connectNo++;
			if (y == BOARDSIZE)
				break;
		}
	}
	if (connectNo >= 5)
		return 1; // 縦の五目並べ見つけた

	// 斜め（北西－南東）の五目並べチェック:(lastx, lasty)座標からcolorと同じ色の石の連結を北西と南東にあわせて数える
	connectNo = 1;
	if (lastX > 1 && lastY > 1)
	{
		for (x = lastX - 1, y = lastY - 1; gomokuBoard[x][y] == color; x--, y--)
		{
			connectNo++;
			if (x == 1 || y == 1)
				break;
		}
	}
	if (lastX < BOARDSIZE && lastY < BOARDSIZE)
	{
		for (x = lastX + 1, y = lastY + 1; gomokuBoard[x][y] == color; x++, y++)
		{
			connectNo++;
			if (x == BOARDSIZE || y == BOARDSIZE)
				break;
		}
	}
	if (connectNo >= 5)
		return 1; // 斜め（北西－南東）の五目並べ見つけた

	// 斜め（北東－南西）の五目並べチェック:(lastx, lasty)座標からcolorと同じ色の石の連結を北東と南西にあわせて数える
	connectNo = 1;
	if (lastX < BOARDSIZE && lastY > 1)
	{
		for (x = lastX + 1, y = lastY - 1; gomokuBoard[x][y] == color; x++, y--)
		{
			connectNo++;
			if (x == BOARDSIZE || y == 1)
				break;
		}
	}
	if (lastX > 1 && lastY < BOARDSIZE)
	{
		for (x = lastX - 1, y = lastY + 1; gomokuBoard[x][y] == color; x--, y++)
		{
			connectNo++;
			if (x == 1 || y == BOARDSIZE)
				break;
		}
	}
	if (connectNo >= 5)
		return 1; // 斜め（北東－南西）の五目並べ見つけた

	return 0;
}

// プレイヤーから新しいてを獲得
void getNextHumanMove()
{
	int legalX, legalY, legalMove;
	int i;
	char c;
	char buf[256];

	legalX = legalY = legalMove = 0;
	// 正しい手を獲得できるまでに繰り返す
	while (!legalMove)
	{
		// 正しいx軸の獲得まで繰り返す
		while (!legalX)
		{
			printf("Enter x coordinate of move (1-15): ");
			c = getchar();
			for (i = 0; c != '\n'; i++)
			{
				buf[i] = c;
				c = getchar();
			}
			buf[i] = '\0';
			sscanf_s(buf, "%d", &nextMoveX);
			if (nextMoveX >= 1 && nextMoveX <= BOARDSIZE)
				legalX = 1;
			else
			{
				printf("The x-coordinate should be a number between 1 and 15.\n");
				nextMoveX = 0;
			}
		}
		// 正しいy軸の獲得まで繰り返す
		while (!legalY)
		{
			printf("Enter y coordinate of move (1-15): ");
			c = getchar();
			for (i = 0; c != '\n'; i++)
			{
				buf[i] = c;
				c = getchar();
			}
			buf[i] = '\0';
			sscanf_s(buf, "%d", &nextMoveY);
			if (nextMoveY >= 1 && nextMoveY <= BOARDSIZE)
				legalY = 1;
			else
			{
				printf("The y-coordinate should be a number between 1 and 15.\n");
				nextMoveY = 0;
			}
		}
		// 選んだマスは空きマスかどうかを確認
		if (gomokuBoard[nextMoveX][nextMoveY] == EMPTY_SQUARE)
			legalMove = 1;
		else
		{
			printf("The selected square is not empty.\n");
			nextMoveX = 0;
			nextMoveY = 0;
			legalX = 0;
			legalY = 0;
		}
	}
}