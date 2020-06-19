#include <stdio.h>

//部屋の情報
struct room {
    int hasHero;   //主人公がいる
	/** doorInfoを配列に変更した **/
    int doorInfo[4];  //ドアの情報
	/** 以下追加した変数 **/
	int hasStinker1;
	int hasStinker2;
	int hasSuperStinker;
	int princeVisited;
	int healthPotion;
	int hasSword;
	int hasPrince;
};

/** dungeonの宣言が無かったので追加した **/
struct room dungeon[6][6];

//主人公の情報
/** GmameHeroになってた **/
struct GameHero {
    int roomX;  // 主人公がいる部屋のX軸
    int roomY;  // 主人公がいる部屋のY軸
	/** 変数を追加した **/
	int healthPoints; //HP
	int hasSword;
};

struct GameHero Hero;
struct GameHero prince;

// ドアの状況
#define noDoor 0
#define openDoor 1

// 方向
#define North 0
#define East 1
#define South 2
#define West 3

void initialiseHero();
/** 関数のプロトタイプ宣言が足りてなかったから追加した **/
void initialiseDungeon();
void printGameExplanation();
int UserMove();
int moveHero(int);

int main(void) {
    char c;
    int moveDirection;  // 移動方向

    initialiseDungeon();     // ダンジョンの初期化
    initialiseHero();        // 主人公の情報を初期化
    printGameExplanation();  // ゲームのルールを表示

    while (1) {
        moveDirection = UserMove();  //移動方向入力
        moveHero(moveDirection);     //主人公移動
    }
    /** メイン関数が閉じてなかったのでここで閉じた **/
}

//主人公の情報を初期化
void initialiseHero() {
    Hero.roomX = 1;
    Hero.roomY = 1;
}

// ゲームのルールと目的を説明する
void printGameExplanation() {
    char c, userSelection;

    printf("1) ゲームのルール説明\n");
    printf("2) ゲームスタート\n");
    /** セミコロンが大文字になってた **/
    printf("どちらかのキーを選んでください: ");
    // ユーザの選択を獲得
    c = getchar();
    userSelection = c;
    /**
     * while文の後ろにつける{}が;になってた
     **/
    while ((c = getchar()) != '\n') {
        //もし１を選んだら
        if (userSelection == '1') {
            printf("\nルール説明\n");
            printf("==========================\n");
            printf("1:まず座標1:1の部屋からスタート\n");
            printf("2:キーを選んで部屋を移動\n");
            printf("3:敵が現れたら敵を倒す\n");
            printf("4:ラスボスを倒せたらゲームクリア!\n");
            printf("\n何かキーを押してゲームスタート\n");
            c = getchar();
        }
        printf("健闘を祈る\n");
    }
    /** printGameDitection() が終わってなかったのでここで}を足して終わらせた **/
}

// ダンジョンの情報を画面に表示する
// 一つの部屋は5x5の大きさにする
// 1列目：北ドア、2列目：見やすくするための空きスペース、3列目：匂い、
// 4列目：西ドア、プリンスとStinker、東ドア、5列目：刀と健康ポーション、6列目：南ドア
void showDungeon() {
    int x, y;

    // 部屋を一つずつ表示する
    for (y = 1; y <= 5; y++) {
        // 1列目：北ドア
        for (x = 1; x <= 5; x++) {
            if (dungeon[x][y].princeVisited) {
                if (dungeon[x][y].doorInfo[North] == noDoor) {
                    printf("*******");
                } else if (dungeon[x][y].doorInfo[North] == openDoor) {
                    printf("***D***");
                }

            } else {
                printf("       ");
            }
        }
        printf("\n");

        // 2列目：見やすくするための空きスペース
        for (x = 1; x <= 5; x++) {
            if (dungeon[x][y].princeVisited) {
                printf("*     *");
            } else {
                printf("       ");
            }
        }
        printf("\n");

        // 4列目：西ドア、プリンスとStinker、東ドア
        for (x = 1; x <= 5; x++) {
            if (dungeon[x][y].princeVisited) {
                if (dungeon[x][y].doorInfo[West] == noDoor) {
                    printf("* ");
                } else if (dungeon[x][y].doorInfo[West] == openDoor) {
                    printf("D ");
                }
                if (dungeon[x][y].hasPrince) {
                    if (prince.hasSword) {
                        printf("P!");
                    } else {
                        printf("P ");
                    }
                } else {
                    printf("  ");
                }
                if (dungeon[x][y].hasStinker1 || dungeon[x][y].hasStinker2) {
                    printf("S ");
                } else if (dungeon[x][y].hasSuperStinker) {
                    printf("$ ");
                } else {
                    printf("  ");
                }
                if (dungeon[x][y].doorInfo[East] == noDoor) {
                    printf("*");
                } else if (dungeon[x][y].doorInfo[East] == openDoor) {
                    printf("D");
                }
            } else {
                printf("       ");
            }
        }
        printf("\n");

        // 5列目：刀と健康ポーション
        for (x = 1; x <= 5; x++) {
            if (dungeon[x][y].princeVisited) {
                if (dungeon[x][y].hasSword) {
                    printf("* K ");
                } else {
                    printf("*   ");
                }
                if (dungeon[x][y].healthPotion) {
                    printf("H *");
                } else {
                    printf("  *");
                }
            } else {
                printf("       ");
            }
        }
        printf("\n");

        // 6列目：南ドア
        for (x = 1; x <= 5; x++) {
            if (dungeon[x][y].princeVisited) {
                if (dungeon[x][y].doorInfo[South] == noDoor) {
                    printf("*******");
                } else if (dungeon[x][y].doorInfo[South] == openDoor) {
                    printf("***D***");
                }
            } else {
                printf("       ");
            }
        }
        printf("\n");
    }

    // 記号の説明
    printf("P = Prince, S = Stinker, $ = Super Stinker\n");
    printf("& = Stinker smell, # = Super Stinker smell\n");
    printf("K = Sword, P! = Prince has sword, H = Health potion\n");
    printf("D = Open Door, L = Locked door, * = Wall \n");

    // プリンスの健康状況を表示
    printf("Prince HP: %d\n", prince.healthPoints);
}

// 部屋の情報を表示する
void showRoomInfo() {
    int x = prince.roomX;
    int y = prince.roomY;

    // この部屋にStinkerかSuper Stinkerがいることを表示
    if (dungeon[x][y].hasStinker1 || dungeon[x][y].hasStinker2) {
        printf("There is a Stinker in this room\n");
    }
    if (dungeon[x][y].hasSuperStinker) {
        printf("There is a Super Stinker in this room\n");
    }
    // この部屋に刀があることを表示
    if (dungeon[x][y].hasSword) {
        printf("There is a sword in this room\n");
    }
    // この部屋に健康ポーションがあることを表示
    if (dungeon[x][y].healthPotion) {
        printf("There is a health potion in this room\n");
    }
    // この部屋のドア情報を表示
    if (dungeon[x][y].doorInfo[North] == openDoor) {
        printf("There is a door to the North\n");
    }
    if (dungeon[x][y].doorInfo[East] == openDoor) {
        printf("There is a door to the East\n");
    }
    if (dungeon[x][y].doorInfo[South] == openDoor) {
        printf("There is a door to the South\n");
    }
    if (dungeon[x][y].doorInfo[West] == openDoor) {
        printf("There is a door to the West\n");
    }
}

int UserMove() {
    int direction = -1;
    int legalDirection = 0;
    char c;
    int x = prince.roomX;
    int y = prince.roomY;

    // 正しい方向が入力されてないまで繰り返す
    while (!legalDirection) {
        // ユーザーから方向を入力
        printf("移動したい方向を入力してください (N,E,S,W): ");
        c = getchar();
        // 改行文字をバッファーから削除
        scanf("%*c");

        // 入力は正しいかどうかを確認
        switch (c) {
            case 'N':
                // 北方向にドアがあれば方向決定
                if (dungeon[x][y].doorInfo[North] == openDoor) {
                    direction = North;
                    legalDirection = 1;
                } else {
                    printf("この方向には移動できません\n");
                }
                break;
            case 'E':
                // 東方向にドアがあれば方向決定
                if (dungeon[x][y].doorInfo[East] == openDoor) {
                    direction = East;
                    legalDirection = 1;
                } else {
                    printf("この方向には移動できません\n");
                }
                break;
            case 'S':
                // 南方向にドアがあれば方向決定
                if (dungeon[x][y].doorInfo[South] == openDoor) {
                    direction = South;
                    legalDirection = 1;
                } else {
                    printf("この方向には移動できません\n");
                }
                break;
            case 'W':
                // 西方向にドアがあれば方向決定
                if (dungeon[x][y].doorInfo[West] == openDoor) {
                    direction = West;
                    legalDirection = 1;
                } else {
                    printf("この方向には移動できません\n");
                }
                break;
            default:
                // 不正入力
                printf("この方向には移動できません\n");
                break;
        }
    }
	/** directionを返すように変更した **/
	return direction;
}