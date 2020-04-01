#include <bits/stdc++.h>

using namespace std;

int R[100009];
int n;

/*
* 基準値x以下の値を左から並べていって、どれくらい左に並べたかをiに持っておく
* 最後に、右端においてあった基準を左から並べた一個右側におく
*/
int partition(int q, int r){
    int x = R[r];
    int i = q - 1;
    for(int j = q; j < r; j ++){
        if( R[j] <= x){
            i = i + 1;
            int temp = R[i];
            R[i] = R[j];
            R[j] = temp;
        }
    }
    int temp = R[r];
    R[r] = R[i + 1];
    R[i + 1] = temp;
    return i + 1;
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> R[i];
    }
    int r = partition(0, n-1);
    for(int i = 0; i < n-1; i++){
        if(i == r){
            cout << "[" << R[r] << "]" << " ";
            continue;
        }
        cout << R[i] << " ";
    }
    cout << R[n-1] << endl;
    return 0;
}