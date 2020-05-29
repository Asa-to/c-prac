#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// マスの情報
#define EMPTY_SQUARE	0		// 空きマス
#define BLACK_STONE		1		// 黒い石
#define WHITE_STONE		2		// 白い石

//　手番
#define BLACK			1		// 黒の手番
#define WHITE			2		// 白の手番

// 五目並べの盤の大きさは15
#define BOARDSIZE		15

// COMと人間はプレイヤー
#define HUMAN				1		// 人間
#define FIRST_FREE_AI		2		// このAIは最初の空いているマスに石を置く
#define RANDOM_AI			3		// このAIは空いているマスをランダムに選択する
#define ONE_MOVE_SEARCH_AI	4	// 一手先読みのAI

char namesAI[][16] = { "", "", "FirstFreeAI", "RandomAI", "OneMoveSearchAI" };

// ゲームの結果
#define UNFINISHED		0		// まだ終わっていない
#define BLACK_WIN		1		// 先手の勝ち
#define WHITE_WIN		2		// 後手の勝ち
#define DRAW			3		// 引き分け

// 特別な評価値
#define INFINITYVAL		32000	// 無限大
#define WINNING			30000	// 勝ち

// 先手と後手はCOMか人間かを管理する変数
int blackPlayer;
int whitePlayer;

int gomokuBoard[BOARDSIZE + 1][BOARDSIZE + 1];  // 五目並べの盤
int nextMoveX;										// 次の手のx軸
int nextMoveY;										// 次の手のy軸

int numberOfGames;			// 自己対戦の場合、対局の数

int rootToMove;		// 探索の初期局面の手番

					// データを保存するための変数
int saveData;
FILE *dataFile;

// 手を保存する構造体
// 五目並べには必要ないだが、一般的なゲームの練習のために重要
typedef struct
{
	int x; // 手のx軸
	int y; // 手のy軸
} Move;

//
// 盤のマスの評価
//
// 中央に近い石を高く評価するための配列．
// 数字の決め方：マスから可能な五目並べの数
// 過度は最低3、端から離れたマスは最大8ので評価のボーナス値は0から5まで．
int potentialEvaluation[BOARDSIZE + 1][BOARDSIZE + 1] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
{ 0, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2 },
{ 0, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2 },
{ 0, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2 },
{ 0, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2 },
{ 0, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2 },
{ 0, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2 },
{ 0, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2 },
{ 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
};

// 局面に同じ色の石の連結を管理するための偏す
int blackOpenFour;		// 黒い石を四つ並びの数、ブロックなし： * B B B B *
int blackClosedFour;	// 黒い石を四つ並びの数、白い石のブロック (W B B B B *) か盤の端にブロック (E B B B B *)
int blackOpenThree;		// 黒い石を三つ並びの数、ブロックなし： * B B B *
int blackClosedThree;	// 黒い石を三つ並びの数、白い石のブロック (W B B B *) か盤の端にブロック (E B B B *)
int blackOpenTwo;		// 黒い石を二つ並びの数、ブロックなし： * B B *
int blackClosedTwo;		// 黒い石を二つ並びの数、白い石のブロック (W B B *) か盤の端にブロック (E B B *)
int whiteOpenFour;		// 白い石を四つ並びの数、黒と同様
int whiteClosedFour;	// 白い石を四つ並びの数、黒と同様
int whiteOpenThree;		// 白い石を三つ並びの数、黒と同様
int whiteClosedThree;	// 白い石を三つ並びの数、黒と同様
int whiteOpenTwo;		// 白い石を二つ並びの数、黒と同様
int whiteClosedTwo;		// 白い石を二つ並びの数、黒と同様

						// OPEN_TWO_VALUEを基本の手とし、得点5の二手は相手の次手を制限することができるので、OPNE_TWO_VALUE2つ分以上の価値に設定。
                        // CLOSED_THREE_VALUEは、ほかにもう一か所勝ちにつながる場所が出れば十分に強いので、OPEN_TWO_VALUEの1つだけ下の価値にした。
                        // CLOSE_TWO_VALUEは 2手分あっても脅威にならないため、これ一つに判断が大きく左右されないよう低めの価値にした。
#define CLOSED_FOUR_VALUE	7 //次の手番で防がれなければ勝てる
#define OPEN_THREE_VALUE	9 //次の手番で防がれなければ勝てる
#define CLOSED_THREE_VALUE	4 //次とその次の手番で防がれなければ勝てる。これだけを作ることはあまり意味がない.
#define OPEN_TWO_VALUE		5 //基本の一手。この状態を複数持つことで勝ち幅が広がる。
#define CLOSED_TWO_VALUE	1 //弱い

						// 関数のプロトタイプ
void makeBoardEmpty();
void showBoard();
void saveBoardToFile(FILE *);
int selectAI(int);
int playGomokuGame();
int fiveInRowCheck(int, int, int);
void getNextHumanMove();
int getNumberOfGames();
int decideComputerMove(int);
int firstFreeSquareAI(int);
int randomFreeSquareAI(int);
int oneMoveSearch(int);
int generateMoves(Move *);
int evaluate(int, int);
void blackConnectionAdmin(int, int, int);
void whiteConnectionAdmin(int, int, int);

int main()
{
	char c, userSelection, i;
	int gameResult;
	int firstAI, secondAI;
	int firstAIWins, secondAIWins, drawNumber;
	int tempPlayer;
	char dataFileName[100];

	while (1)
	{
		// 乱数の初期化
		srand(time(NULL));

		// とりあえず、データは保存しない
		saveData = 0;

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
		printf("2) Play with black against computer\n");
		printf("3) Play with white against computer\n");
		printf("4) Play computer against computer\n");
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

		case '2':
			// COMは白の場合にプレイヤーを初期化
			whitePlayer = selectAI(WHITE);
			// ゲームを最初から最後までやる
			if (whitePlayer)
			{
				blackPlayer = HUMAN;
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
			}
			break;

		case '3':
			// COMは黒の場合にプレイヤーを初期化
			blackPlayer = selectAI(BLACK);
			if (blackPlayer)
			{
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
			}
			break;

		case '4':
			// COMvsCOM
			blackPlayer = selectAI(BLACK);
			whitePlayer = selectAI(WHITE);

			// ゲームを最初から最後までやる
			if (blackPlayer && whitePlayer)
			{

				firstAI = blackPlayer;
				secondAI = whitePlayer;

				numberOfGames = getNumberOfGames();

				// データを保存する準備
//				printf("Enter filename to save data: ");
//				scanf_s("%s", dataFileName);
//				scanf_s("%*c");
//				fopen_s(&dataFile, dataFileName, "w");
				if (dataFile == NULL)
					printf("Unable to open data file\n");
				else
					saveData = 1;

				firstAIWins = secondAIWins = drawNumber = 0;

				for (i = 1; i <= numberOfGames; i++)
				{
					printf("Starting game number %d\n", i);
					if (saveData)
						fprintf(dataFile, "Starting game number %d\n", i);

					gameResult = playGomokuGame();

					// 結果を表示
					if (gameResult == BLACK_WIN)
					{
						printf("\nBlack player wins.\n");
						if (saveData)
							fprintf(dataFile, "\nBlack player wins.\n");
					}
					else if (gameResult == WHITE_WIN)
					{
						printf("\nWhite player wins.\n");
						if (saveData)
							fprintf(dataFile, "\nWhite player wins.\n");
					}
					else if (gameResult == DRAW)
					{
						printf("\nThis game ended in a draw.\n");
						if (saveData)
							fprintf(dataFile, "\nThis game ended in a draw.\n");
					}

					// 途中結果を更新
					if ((gameResult == BLACK_WIN && blackPlayer == firstAI) ||
						(gameResult == WHITE_WIN && whitePlayer == firstAI))
						firstAIWins++;
					else if ((gameResult == BLACK_WIN && blackPlayer == secondAI) ||
						(gameResult == WHITE_WIN && whitePlayer == secondAI))
						secondAIWins++;
					else if (gameResult == DRAW)
						drawNumber++;
					// 黒と白を入れ替えて、次の対局をやる
					if (i != numberOfGames)
					{
						printf("\nCurrent score: %s - %s %d-%d(%d)\n\n", namesAI[firstAI], namesAI[secondAI], firstAIWins, secondAIWins, drawNumber);
						if (saveData)
							fprintf(dataFile, "\nCurrent Score: %s - %s %d-%d(%d)\n\n", namesAI[firstAI], namesAI[secondAI], firstAIWins, secondAIWins, drawNumber);

						tempPlayer = blackPlayer;
						blackPlayer = whitePlayer;
						whitePlayer = tempPlayer;
						makeBoardEmpty();
						showBoard();
					}

				}

				// 最終結果を表示
				printf("\nFinal result: %s - %s %d-%d(%d)\n\n", namesAI[firstAI], namesAI[secondAI], firstAIWins, secondAIWins, drawNumber);
				if (saveData) {
					fprintf(dataFile, "\nFinal result: %s - %s %d-%d(%d)\n\n", namesAI[firstAI], namesAI[secondAI], firstAIWins, secondAIWins, drawNumber);
					fclose(dataFile);
				}

				printf("Press any key to continue.\n");
				while ((c = getchar()) != '\n')
					;
			}
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

// 現在の局面をファイルに保存
void saveBoardToFile(FILE *fp)
{
	int x, y;

	fprintf(fp, "   １ ２ ３ ４ ５ ６ ７ ８ ９ 10 11 12 13 14 15\n");
	for (y = 1; y <= BOARDSIZE; y++)
	{
		if (y < 10)
			fprintf(fp, " %d", y);
		else
			fprintf(fp, "%d", y);
		for (x = 1; x <= BOARDSIZE; x++)
		{
			if (gomokuBoard[x][y] == BLACK_STONE)
				fprintf(fp, " ○");
			else if (gomokuBoard[x][y] == WHITE_STONE)
				fprintf(fp, " ●");
			else
				fprintf(fp, " ＊");
		}
		fprintf(fp, "\n");
	}
}

// ユーザにAIを選択してもらう
int selectAI(int color)
{
	char c, userSelection;

	while (1)
	{
		// メーンメニュを表示
		if (color == BLACK)
			printf("\nSelect computer AI for black:\n");
		else
			printf("\nSelect computer AI for white:\n");
		printf("1) Put stone on first empty square\n");
		printf("2) Put stone on random empty square\n");
		printf("3) One move search\n");
		printf("Q) Return to main menu\n");
		printf("Please enter your selection: ");

		c = getchar();
		userSelection = c;
		while ((c = getchar()) != '\n')
			;

		switch (userSelection)
		{
		case '1':
			return FIRST_FREE_AI;

		case '2':
			return RANDOM_AI;

		case '3':
			return ONE_MOVE_SEARCH_AI;

		case 'Q':
			return 0;

		default:
			printf("Illegal input: Please select one of the menu options.\n");
			break;
		}
	}
	return 0;
}

// 対局の数をユーザに入力してもらう
int getNumberOfGames()
{
	int game_number = 1;

	printf("\nEnter number of games to play: ");
	scanf_s("%d", &game_number);
	scanf_s("%*c");

	return game_number;
}

// 人間対COMの対局．ゲームが終わるまでに以下のことを繰り返す；
// 1) COMの手番にCOMの手を決める
// 2) 人間の手番の場合に人間の手を獲得
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
		if ((toMove == BLACK && blackPlayer != HUMAN) ||
			(toMove == WHITE && whitePlayer != HUMAN))
		{
			// COMの手番
			printf("Thinking about my move...\n");
			if (saveData)
				fprintf(dataFile, "Thinking about my move...\n");
			if (decideComputerMove(toMove))
			{
				printf("Computer move: %d) (%d,%d)\n", moveCount, nextMoveX, nextMoveY);
				if (saveData)
					fprintf(dataFile, "Computer move: %d) (%d,%d)\n", moveCount, nextMoveX, nextMoveY);
			}
			else //	COMの手は決められない
			{
				printf("Computer move could not be decided.\n");
				if (saveData)
					fprintf(dataFile, "Computer move could not be decided.\n");
				if (blackPlayer != HUMAN)
					gameResult = WHITE_WIN;
				else
					gameResult = BLACK_WIN;
				break;
			}
		}
		else
		{
			// 人間の手番
			getNextHumanMove();
			printf("You played: %d) (%d,%d)\n", moveCount, nextMoveX, nextMoveY);
			if (saveData)
				fprintf(dataFile, "You played: %d) (%d,%d)\n", moveCount, nextMoveX, nextMoveY);
		}

		// 石を盤に置く
		if (toMove == BLACK)
			gomokuBoard[nextMoveX][nextMoveY] = BLACK_STONE;
		else
			gomokuBoard[nextMoveX][nextMoveY] = WHITE_STONE;

		// 更新した局面を表示
		showBoard();
		if (saveData)
			saveBoardToFile(dataFile);

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
		else if (moveCount == (BOARDSIZE*BOARDSIZE))	// 盤はいっぱいになったかどうか
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
		return 1;			// 横の五目並べ見つけた

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
		return 1;			// 縦の五目並べ見つけた

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
		return 1;			// 斜め（北西－南東）の五目並べ見つけた

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
		return 1;			// 斜め（北東－南西）の五目並べ見つけた

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

// COMの手を決める．これは五目並べプログラムのAIの部分．
int decideComputerMove(int toMove)
{
	int score;
	int which_ai;

	// AIの選択
	if (toMove == BLACK)
		which_ai = blackPlayer;
	else
		which_ai = whitePlayer;

	rootToMove = toMove;

	switch (which_ai)
	{
	case FIRST_FREE_AI:
		score = firstFreeSquareAI(rootToMove);
		printf("Best move evaluation: %d\n", score);
		if (saveData)
			fprintf(dataFile, "Best move evaluation: %d\n", score);
		break;

	case RANDOM_AI:
		score = randomFreeSquareAI(rootToMove);
		printf("Best move evaluation: %d\n", score);
		if (saveData)
			fprintf(dataFile, "Best move evaluation: %d\n", score);
		break;

	case ONE_MOVE_SEARCH_AI:
		score = oneMoveSearch(rootToMove);
		printf("Best move evaluation: %d\n", score);
		if (saveData)
			fprintf(dataFile, "Best move evaluation: %d\n", score);
		break;

	default:
		break;

	}
	return 1;
}

// 単純AI：最初に空いているマスに石を置く
int firstFreeSquareAI(int toMove)
{
	int i, legalMoveNo;
	Move allMoves[BOARDSIZE * BOARDSIZE + 1];

	legalMoveNo = generateMoves(allMoves);

	for (i = 1; i <= legalMoveNo; i++)
	{
		if (gomokuBoard[allMoves[i].x][allMoves[i].y] == EMPTY_SQUARE)
		{
			nextMoveX = allMoves[i].x;
			nextMoveY = allMoves[i].y;
			return 0;
		}
	}

	return -1;

}

// 単純AI：空いているマスをランダムに選択する
// 方法：空いているマスを保存して、そのなかの一つをランダムで選択する
int randomFreeSquareAI(int toMove)
{
	int legalMoveNo, selection;
	Move allMoves[BOARDSIZE * BOARDSIZE + 1];

	legalMoveNo = generateMoves(allMoves);

	// 空いているマスから一つをランダムで選択する
	selection = rand() % legalMoveNo;
	nextMoveX = allMoves[selection].x;
	nextMoveY = allMoves[selection].y;

	return 0;
}

// 簡単な一手探索
// 五目並べの盤の空きマスに対して
// 1) 正しい色の石を盤に置く
// 2) 局面を評価する
// 3) 一番高い評価の手を保存する
int oneMoveSearch(int toMove)
{
	int score, eval;
	int x, y;
	int i, legalMoveNo;
	Move allMoves[BOARDSIZE * BOARDSIZE + 1];

	// MaxとMinプレイヤーの評価値を初期化
	if ((toMove == BLACK && blackPlayer == ONE_MOVE_SEARCH_AI) ||
		(toMove == WHITE && whitePlayer == ONE_MOVE_SEARCH_AI))
		score = -INFINITYVAL;
	else
		score = INFINITYVAL;

	legalMoveNo = generateMoves(allMoves);

	// すべての手を調べるため正しい色の石をひとつずつ盤に置く
	for (i = 1; i <= legalMoveNo; i++)
	{
		x = allMoves[i].x;
		y = allMoves[i].y;
		if (gomokuBoard[x][y] == EMPTY_SQUARE)
		{
			// 石を盤に置く
			if (toMove == BLACK)
				gomokuBoard[x][y] = BLACK_STONE;
			else
				gomokuBoard[x][y] = WHITE_STONE;

			// 置いた石は五目並べになったかどうかのチェック
			if (fiveInRowCheck(x, y, toMove))
			{
				// 石を盤から削除
				gomokuBoard[x][y] = EMPTY_SQUARE;
				// COMの手を決定（勝ち）
				nextMoveX = x;
				nextMoveY = y;
				return WINNING;
			}
			else
			{
				// 石を置いた局面を評価
				if (toMove == BLACK)
					eval = evaluate(rootToMove, WHITE);
				else
					eval = evaluate(rootToMove, BLACK);

				// 石を盤から削除
				gomokuBoard[x][y] = EMPTY_SQUARE;
				// 現在の手は今までの最高評価の手より良い手かどうかをチェック
				if (eval > score)
				{
					score = eval;
					// 現在の手は最高だったので保存する
					nextMoveX = x;
					nextMoveY = y;
				}
			}
		}
	}
	return score;
}

// 現在の局面の手を全て作成と保存
int generateMoves(Move *moves)
{
	int x, y;
	int movNo = 0;

	for (x = 1; x <= BOARDSIZE; x++)
	{
		for (y = 1; y <= BOARDSIZE; y++)
		{
			if (gomokuBoard[x][y] == EMPTY_SQUARE)
			{
				movNo++;
				moves[movNo].x = x;
				moves[movNo].y = y;
			}
		}
	}
	return movNo;
}

// 現在の局面を評価
// 正の値は黒い石のパターンに対しての評価なので白の評価であれば評価値を正負逆にする必要がある．
// 勝ち判断のために現在の局面の手番（nextToMove）も必要．
// 北、北西、西、南西方向の連結確認はしなくてよい．（盤の調べる方向ですでに発見されました）
// この評価関数は効率が悪いし、値が調整していないので改善余地が十分ある．
int evaluate(int side, int nextToMove)
{
	int eval = 0;
	int x, y;
	int connectNo;			// 連続の同じ色の石の数
	int emptySqCon;			// 連結はどこまで伸ばせる
	int blocked;			// 石の連結はブロックされている
	int countX, countY;

	blackOpenFour = 0;
	blackClosedFour = 0;
	blackOpenThree = 0;
	blackClosedThree = 0;
	blackOpenTwo = 0;
	blackClosedTwo = 0;
	whiteOpenFour = 0;
	whiteClosedFour = 0;
	whiteOpenThree = 0;
	whiteClosedThree = 0;
	whiteOpenTwo = 0;
	whiteClosedTwo = 0;

	for (x = 1; x <= BOARDSIZE; x++)
	{
		for (y = 1; y <= BOARDSIZE; y++)
		{

			if (gomokuBoard[x][y] == BLACK_STONE)
			{
				// このマスから黒い石を数える

				// 北東方向
				connectNo = 1;
				emptySqCon = 0;

				// 石の連結は盤の端か相手の石にブロックされている
				if (x == 1 || y == BOARDSIZE || gomokuBoard[x - 1][y + 1] == WHITE_STONE)
					blocked = 1;
				else {
					blocked = 0;
					emptySqCon++;
				}

				// 石の連結を数える
				for (countX = x + 1, countY = y - 1; countX <= BOARDSIZE && countY >= 1; countX++, countY--)
				{
					if (gomokuBoard[countX][countY] == BLACK_STONE)
					{
						connectNo++;
					}
					else if (gomokuBoard[countX][countY] == WHITE_STONE)
					{
						blocked++;
						break;
					}
					else
					{
						break;
					}
				}
				// どこまで伸ばせるか
				if (blocked <= 1 && connectNo > 1) {
					for (; countX <= BOARDSIZE && countY >= 1 && gomokuBoard[countX][countY] == EMPTY_SQUARE; countX++, countY--)
						emptySqCon++;
				}
				// 石の連結の種類の数を更新
				blackConnectionAdmin(connectNo, blocked, emptySqCon);

				// 東方向
				connectNo = 1;
				emptySqCon = 0;

				// 石の連結は盤の端か相手の石にブロックされている
				if (x == 1 || gomokuBoard[x - 1][y] == WHITE_STONE)
					blocked = 1;
				else {
					blocked = 0;
					emptySqCon++;
				}

				// 石の連結を数える
				countY = y;
				for (countX = x + 1; countX <= BOARDSIZE; countX++)
				{
					if (gomokuBoard[countX][countY] == BLACK_STONE)
					{
						connectNo++;
					}
					else if (gomokuBoard[countX][countY] == WHITE_STONE)
					{
						blocked++;
						break;
					}
					else
					{
						break;
					}
				}
				// どこまで伸ばせるか
				if (blocked <= 1 && connectNo > 1) {
					for (; countX <= BOARDSIZE && gomokuBoard[countX][countY] == EMPTY_SQUARE; countX++)
						emptySqCon++;
				}
				// 石の連結の種類の数を更新
				blackConnectionAdmin(connectNo, blocked, emptySqCon);

				// 南東方向
				connectNo = 1;
				emptySqCon = 0;

				// 石の連結は盤の端か相手の石にブロックされている
				if (x == 1 || y == 1 || gomokuBoard[x - 1][y - 1] == WHITE_STONE)
					blocked = 1;
				else {
					blocked = 0;
					emptySqCon++;
				}

				// 石の連結を数える
				for (countX = x + 1, countY = y + 1; countX <= BOARDSIZE && countY <= BOARDSIZE; countX++, countY++)
				{
					if (gomokuBoard[countX][countY] == BLACK_STONE)
					{
						connectNo++;
					}
					else if (gomokuBoard[countX][countY] == WHITE_STONE)
					{
						blocked++;
						break;
					}
					else
					{
						break;
					}
				}
				// どこまで伸ばせるか
				if (blocked <= 1 && connectNo > 1) {
					for (; countX <= BOARDSIZE && countY <= BOARDSIZE && gomokuBoard[countX][countY] == EMPTY_SQUARE; countX++, countY++)
						emptySqCon++;
				}
				// 石の連結の種類の数を更新
				blackConnectionAdmin(connectNo, blocked, emptySqCon);

				// 南方向
				connectNo = 1;
				emptySqCon = 0;

				// 石の連結は盤の端か相手の石にブロックされている
				if (y == 1 || gomokuBoard[x][y - 1] == WHITE_STONE)
					blocked = 1;
				else {
					blocked = 0;
					emptySqCon++;
				}

				// 石の連結を数える
				countX = x;
				for (countY = y + 1; countY <= BOARDSIZE; countY++)
				{
					if (gomokuBoard[countX][countY] == BLACK_STONE)
					{
						connectNo++;
					}
					else if (gomokuBoard[countX][countY] == WHITE_STONE)
					{
						blocked++;
						break;
					}
					else
					{
						break;
					}
				}
				// どこまで伸ばせるか
				if (blocked <= 1 && connectNo > 1) {
					for (; countY <= BOARDSIZE && gomokuBoard[countX][countY] == EMPTY_SQUARE; countY++)
						emptySqCon++;
				}
				// 石の連結の種類の数を更新
				blackConnectionAdmin(connectNo, blocked, emptySqCon);

			}
			else if (gomokuBoard[x][y] == WHITE_STONE)
			{
				// このマスから黒い石を数える

				// 北東方向
				connectNo = 1;
				emptySqCon = 0;

				// 石の連結は盤の端か相手の石にブロックされている
				if (x == 1 || y == BOARDSIZE || gomokuBoard[x - 1][y + 1] == BLACK_STONE)
					blocked = 1;
				else {
					blocked = 0;
					emptySqCon++;
				}

				// 石の連結を数える
				for (countX = x + 1, countY = y - 1; countX <= BOARDSIZE && countY >= 1; countX++, countY--)
				{
					if (gomokuBoard[countX][countY] == WHITE_STONE)
					{
						connectNo++;
					}
					else if (gomokuBoard[countX][countY] == BLACK_STONE)
					{
						blocked++;
						break;
					}
					else
					{
						break;
					}
				}
				// どこまで伸ばせるか
				if (blocked <= 1 && connectNo > 1) {
					for (; countX <= BOARDSIZE && countY >= 1 && gomokuBoard[countX][countY] == EMPTY_SQUARE; countX++, countY--)
						emptySqCon++;
				}
				// 石の連結の種類の数を更新
				whiteConnectionAdmin(connectNo, blocked, emptySqCon);

				// 東方向
				connectNo = 1;
				emptySqCon = 0;

				// 石の連結は盤の端か相手の石にブロックされている
				if (x == 1 || gomokuBoard[x - 1][y] == BLACK_STONE)
					blocked = 1;
				else {
					blocked = 0;
					emptySqCon++;
				}

				// 石の連結を数える
				countY = y;
				for (countX = x + 1; countX <= BOARDSIZE; countX++)
				{
					if (gomokuBoard[countX][countY] == WHITE_STONE)
					{
						connectNo++;
					}
					else if (gomokuBoard[countX][countY] == BLACK_STONE)
					{
						blocked++;
						break;
					}
					else
					{
						break;
					}
				}
				// どこまで伸ばせるか
				if (blocked <= 1 && connectNo > 1) {
					for (; countX <= BOARDSIZE && gomokuBoard[countX][countY] == EMPTY_SQUARE; countX++)
						emptySqCon++;
				}
				// 石の連結の種類の数を更新
				whiteConnectionAdmin(connectNo, blocked, emptySqCon);

				// 南東方向
				connectNo = 1;
				emptySqCon = 0;

				// 石の連結は盤の端か相手の石にブロックされている
				if (x == 1 || y == 1 || gomokuBoard[x - 1][y - 1] == BLACK_STONE)
					blocked = 1;
				else {
					blocked = 0;
					emptySqCon++;
				}

				// 石の連結を数える
				for (countX = x + 1, countY = y + 1; countX <= BOARDSIZE && countY <= BOARDSIZE; countX++, countY++)
				{
					if (gomokuBoard[countX][countY] == WHITE_STONE)
					{
						connectNo++;
					}
					else if (gomokuBoard[countX][countY] == BLACK_STONE)
					{
						blocked++;
						break;
					}
					else
					{
						break;
					}
				}
				// どこまで伸ばせるか
				if (blocked <= 1 && connectNo > 1) {
					for (; countX <= BOARDSIZE && countY <= BOARDSIZE && gomokuBoard[countX][countY] == EMPTY_SQUARE; countX++, countY++)
						emptySqCon++;
				}
				// 石の連結の種類の数を更新
				whiteConnectionAdmin(connectNo, blocked, emptySqCon);

				// 南方向（この場合にダブルカウントはないので確認しなくてよい）
				connectNo = 1;
				emptySqCon = 0;

				// 石の連結は盤の端か相手の石にブロックされている
				if (y == 1 || gomokuBoard[x][y - 1] == BLACK_STONE)
					blocked = 1;
				else {
					blocked = 0;
					emptySqCon++;
				}

				// 石の連結を数える
				countX = x;
				for (countY = y + 1; countY <= BOARDSIZE; countY++)
				{
					if (gomokuBoard[countX][countY] == WHITE_STONE)
					{
						connectNo++;
					}
					else if (gomokuBoard[countX][countY] == BLACK_STONE)
					{
						blocked++;
						break;
					}
					else
					{
						break;
					}
				}
				// どこまで伸ばせるか
				if (blocked <= 1 && connectNo > 1) {
					for (; countY <= BOARDSIZE && gomokuBoard[countX][countY] == EMPTY_SQUARE; countY++)
						emptySqCon++;
				}
				// 石の連結の種類の数を更新
				whiteConnectionAdmin(connectNo, blocked, emptySqCon);

			}

			// 盤の中央に近い石の評価を高くする
			if (side == BLACK && gomokuBoard[x][y] == BLACK_STONE)
				eval += potentialEvaluation[x][y];
			else if (side == WHITE && gomokuBoard[x][y] == WHITE_STONE)
				eval -= potentialEvaluation[x][y];
		}
	}

	// 連結に値を付ける
	if ((blackOpenFour || blackClosedFour) && nextToMove == BLACK)
		eval = WINNING;					// 黒の手番と長さ４の連結あり
	else if ((whiteOpenFour || whiteClosedFour) && nextToMove == WHITE)
		eval = -WINNING;				// 白の手番と長さ４の連結あり
	else if (blackOpenFour >= 1)
		eval = WINNING;					// 黒のOpen Four
	else if (whiteOpenFour >= 1)
		eval = -WINNING;				// 白のOpen Four
	else if (blackClosedFour >= 2)
		eval = WINNING;					// 黒は連結４を二つ以上がある
	else if (whiteClosedFour >= 2)
		eval = -WINNING;				// 白は連結４を二つ以上がある
	else {
		//　勝ち以外の連結の評価（黒）
		eval += blackClosedFour * CLOSED_FOUR_VALUE;
		eval += blackOpenThree * OPEN_THREE_VALUE;
		eval += blackClosedThree * CLOSED_THREE_VALUE;
		eval += blackOpenTwo * OPEN_TWO_VALUE;
		eval += blackClosedTwo * CLOSED_TWO_VALUE;

		//　勝ち以外の連結の評価（白）
		eval -= whiteClosedFour * CLOSED_FOUR_VALUE;
		eval -= whiteOpenThree * OPEN_THREE_VALUE;
		eval -= whiteClosedThree * CLOSED_THREE_VALUE;
		eval -= whiteOpenTwo * OPEN_TWO_VALUE;
		eval -= whiteClosedTwo * CLOSED_TWO_VALUE;

	}

	// 白の評価だったら正負逆
	if (side == WHITE)
		return -eval;

	return eval;
}

// 石の連結の種類の数を更新（黒の場合）
void blackConnectionAdmin(int connectNo, int blocked, int openSquare)
{
	if (blocked >= 2) {
		// 連結は完全にブラックされている
	}
	else if (connectNo + openSquare < 5)
	{
		// 連結は５まで伸ばせない
	}
	else if (connectNo == 4)
	{
		// 長さ４の連結を発見した
		if (blocked == 0)
			blackOpenFour++;
		else if (blocked == 1)
			blackClosedFour++;
	}
	else if (connectNo == 3)
	{
		// 長さ３の連結を発見した
		if (blocked == 0)
			blackOpenThree++;
		else if (blocked == 1)
			blackClosedThree++;
	}
	else if (connectNo == 2)
	{
		// 長さ２の連結を発見した
		if (blocked == 0)
			blackOpenTwo++;
		else if (blocked == 1)
			blackClosedTwo++;
	}
}

// 石の連結の種類の数を更新（白の場合）
void whiteConnectionAdmin(int connectNo, int blocked, int openSquare)
{
	if (blocked >= 2) {
		// 連結は完全にブラックされている
	}
	else if (connectNo + openSquare < 4)
	{
		// 連結は５まで伸ばせない
	}
	else if (connectNo == 4)
	{
		// 長さ４の連結を発見した
		if (blocked == 0)
			whiteOpenFour++;
		else if (blocked == 1)
			whiteClosedFour++;
	}
	else if (connectNo == 3)
	{
		// 長さ３の連結を発見した
		if (blocked == 0)
			whiteOpenThree++;
		else if (blocked == 1)
			whiteClosedThree++;
	}
	else if (connectNo == 2)
	{
		// 長さ２の連結を発見した
		if (blocked == 0)
			whiteOpenTwo++;
		else if (blocked == 1)
			whiteClosedTwo++;
	}
}