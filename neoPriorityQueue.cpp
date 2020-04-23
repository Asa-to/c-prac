#include<bits/stdc++.h>

using namespace std;

vector<int> a(2000001);
int H = 0;

int parent(int node){
    return node/2;
}

int left(int node){
    return node*2;
}

int right(int node){
    return node*2+1;
}

//下からえへ遡っていい位置にkeyを挿入する。位置はiがもっている。
void heapIncreaseKey(int i, int key){
    //一旦a[i]にkeyを入れて、ソートする。
    a[i] = key;
    //親子関係が正しくなるまでループ
    while(i > 1 && a[parent(i)] < a[i]){
        swap(a[i], a[parent(i)]);
        i = parent(i);
    }
}

void maxHeapify(int i){
    int l = left(i);
    int r = right(i);
    //自分、左の子、右ノ子の中で最大のノードを選ぶ。
    int maxNode = i;
    if(l <= H && a[i] < a[l])maxNode = l;
    if(r <= H && a[i] < a[r])maxNode = r;
    //iのこのほうが大きければ、交換して再帰
    if(maxNode != i){
        swap(a[i], a[maxNode]);
        maxHeapify(maxNode);
    }
}

//根を取得して消し飛ばす
int heapExtractMax(){
    //万が一ヒープの大きさが1未満なら、エラーを出したい
    if(H < 1)return -1;
    int maxj = a[1];
    //一番後ろの値を一番手間に持ってきて、max-ヒープを作り直す。
    a[1] = a[H];
    //値を一個消したので、ヒープサイズを変更
    H--;
    maxHeapify(1);
    return maxj;
}

void insert(int key){
    H++;
    a[H] = -1;
    heapIncreaseKey(H, key);
}

int main(void){
    string command;
    do{
        cin >> command;
        if(command == "insert"){
            int in;
            cin >> in;
            insert(in);
        }else if(command == "extract"){
            int largest = heapExtractMax();
            cout << largest << endl;
        }
    }while(command != "end");
    return 0;
}