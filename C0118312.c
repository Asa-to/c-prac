/**************************************************************************
   狼と山羊とキャベツと男 (深さ優先探索)
**************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SearchMax 20

//列挙型変数MEMBERSを定義
typedef enum {
  MAN,
  WOLF,
  GOAT,
  CABBAGE,

  MEMBERS_NUM
} MEMBERS;

//便利なので登場人物の名前一覧を配列に用意
char MEM[MEMBERS_NUM][50] = {"男", "狼", "山羊", "キャベツ"};
//チェック用のbit
int manBit = (1);
int wolfBit = (1<<1);
int goatBit = (1<<2);
int cabbageBit = (1<<3);
int lastBit = (1<<4);
int left_side_bit[SearchMax];  /* 左岸の状態 */
int right_side_bit[SearchMax]; /* 右岸の状態 */



/**************************************************************************
  状態の表示
   引数 state_bit : 左岸もしくは右岸の状態
    state_bitの配列の内容に応じて状態を表示する
     (例) state_bit = 1100ならば [ 山羊 キャベツ ]
          state_bit = 0101ならば [ 男 狼 ]
          state_bit = 0ならば [  ]
**************************************************************************/
void print_state_bit(int state_bit) {
  printf("[ ");
  if ((state_bit & manBit) == manBit) printf("%s ", MEM[MAN]);
  if ((state_bit & wolfBit) == wolfBit) printf("%s ", MEM[WOLF]);
  if ((state_bit & goatBit) == goatBit) printf("%s ", MEM[GOAT]);
  if ((state_bit & cabbageBit) == cabbageBit) printf("%s ", MEM[CABBAGE]);
  printf("]");
}

/**************************************************************************
  結果の表示
   引数 T : ステップ数
     Tステップ目までの結果を表示する
      ステップ数: [ 左岸の状態 ] [ 右岸の状態 ]
       (例) 0: [ 男 狼 山羊 キャベツ ] [ ]
            1: [ 狼 山羊 ] [ 男 キャベツ ]
**************************************************************************/
void print_ans(int T) {
    int t;

    /* 初期状態からTステップ目までの結果を表示する
       [ヒント] print_state_bit()の関数が正しく作成されていれば
                 print_state_bit(left_side[t]);  で tステップ目の左岸の状態、
                 print_state_bit(right_side[t]); で tステップ目の右岸の状態
                が表示できる */

    //tステップ目の状態を出力
    for (t = 0; t <= T; t++) {
      printf("%d:", t);
      print_state_bit(left_side_bit[t]);
      print_state_bit(right_side_bit[t]);
      printf("\n");
    }
}

/**************************************************************************
  状態のチェック
   引数 T                 : ステップ数
        state_bit          : チェックしたい状態
        past_state_bit[t]  : 過去の状態(tステップ目の状態)
     ・狼と山羊、山羊とキャベツを残した状態でもなく、既に探索された状態
       でもなければ 1を返す
     ・それ以外は 0を返す
**************************************************************************/
int check_state(int T, int state_bit, int past_state_bit[SearchMax]) {
    int t;

    /* 狼と山羊 もしくは 山羊とキャベツが一緒にないかをチェック
       あれば0を返す */
    if (state_bit == (cabbageBit | goatBit) || state_bit == (wolfBit | goatBit))
        return 0;

    /* 過去に同じ状態がないかをチェック  あれば0を返す
         [ヒント] past_state_bit[t](tステップ目の状態)と
                  state_bit(現在の状態)を比較してチェック */
    for (t = 0; t < T; t++) {
        if (state_bit == past_state_bit[t]) return 0;
    }
    /* いずれにも該当しなければ1を返す */
    return 1;
}

/**************************************************************************
  深さ優先探索
   引数 T                 : ステップ数
        src_side_bit[t]    : 男がいる側の状態
        dest_side_bit[t]   : 男がいない側の状態
**************************************************************************/
void search(int T, int src_side_bit[SearchMax], int dest_side_bit[SearchMax]) {
    int bit;

    int src_state_bit;     /* 男がいる側の状態 */
    int dest_state_bit;    /* 男がいない側の状態 */
    // new_***_stateのコメント分がわかりにくいので変えました。"いつ"男がいたのかが不明瞭です。
    int new_src_state_bit; /* 男がいた側の次のステップの状態 */
    int new_dest_state_bit; /* 男がいなかった側の次のステップでの状態 */

    /* Tステップ目の状態をコピー */
    src_state_bit = src_side_bit[T];
    dest_state_bit = dest_side_bit[T];

    // 1=男,10=狼,100=山羊,1000=キャベツ
    for (bit = 1; bit < lastBit; bit <<= 1) { 
        if ((src_state_bit | bit) == src_state_bit) {
            /* 移動できるのであれば(男と同じ側にいるのであれば) */
            /* bitと男を移動(iが0の場合は男のみ移動)した後の状態を
               new_src_state_bit, new_dest_state_bit に格納
                [ヒント] 現在の状態 (src_state_bit, dest_state_bit)を
                         new_src_state_bit, new_dest_state_bitにコピーし,
                         bitと男が移動した場合に値がどのように変化するかを設定 */

            new_dest_state_bit = dest_state_bit | (manBit | bit);
            new_src_state_bit = src_state_bit & ~(manBit | bit);

            /* bitと男を移動(iが0の場合は男のみ移動)した後の状態が有効かどうかを
               チェックし、有効であれば 岸の状態を更新し、次に進む */
            if (check_state(T, new_src_state_bit, src_side_bit)) {
                /* 男が左岸にいる場合(Tが偶数の場合)
                   left_side[T+1]に new_src_state_bitをコピー
                   right_side[T+1]に new_dest_state_bitをコピー */
                if (T % 2 == 0) {
                    left_side_bit[T+1] = new_src_state_bit;
                    right_side_bit[T+1] = new_dest_state_bit;
                }
                /* 男が右岸にいる場合(Tが奇数の場合)
                   right_side[T+1]に new_src_state_bitをコピー
                   left_side[T+1]に new_dest_state_bitをコピー */
                else {
                    left_side_bit[T+1] = new_dest_state_bit;
                    right_side_bit[T+1] = new_src_state_bit;
                }

                /* 右岸にすべてが移動していれば 結果を表示して終了 */
                if (right_side_bit[T+1] == (manBit | goatBit | wolfBit | cabbageBit)) {
                    print_ans(T + 1);
                    exit(0);
                }else {
                    search(T + 1, dest_side_bit, src_side_bit);
                }
            }
        }
    }
}

/**************************************************************************
  メインプログラム
**************************************************************************/
int main() {
    int i, t;

    /* 配列の初期化 (0を設定) */
    for (t = 0; t < SearchMax; t++) {
        left_side_bit[t] = 0;
        right_side_bit[t] = 0;
    }

    /* 初期状態の設定 */
    left_side_bit[0] = (manBit | wolfBit | goatBit | cabbageBit);

    /* 探索 */
    search(0, left_side_bit, right_side_bit);

    return 0;
}
