#include<bits/stdc++.h>

using namespace std;

void countingSort(int A[], int B[], int k, int n){
    int C[k+1];
    for(int i = 0; i < k+1; i++){
        C[i] = 0;
    }

    //カウンタ配列Cに、Aの各要素の出現回数を保存する
    for(int i = 0; i < n; i++){
        C[A[i]]++;
    }
    //C[i]にi以下の出現回数を記録する(i以下の累積和を取る)
    for(int i = 0; i < k; i++){
        C[i+1] += C[i];
    }
    /*
    *この時点でCには各要素の位置がなんとなくわかるようになっている。
    *例えばi = n;のとき、C[A[i]]にはA[i]の値が何番目に大きい値かが記録されている。
    *A[i]が最大値だった場合、C[A[i]] = nであり、B[A[i]] = A[i]で、出力配列Bの末尾に最大値が記録されるのだ。
    */
    for(int i = n; 0 < i; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}

int main(void){
    int n;
    cin >> n;
    int A[n+1];
    int B[n+1];
    A[0] = 0;
    int maxj = -1;
    for(int i = 0; i < n; i++){
        cin >> A[i+1];
        maxj = max(maxj, A[i+1]);
    }
    countingSort(A, B, maxj, n);
    for(int i = 1; i < n; i++){
        cout << B[i] << " ";
    }
    cout << B[n] << endl;
    return 0;
}