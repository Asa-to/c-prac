#include <bits/stdc++.h>

using namespace std;

//aとbを比較して、aに小さいほうを入れる
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b;return true;}return false;}

//aとbを比較して、aに大きいほうを入れる
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b;return true;}return false;}

int n;

bool call(int A[], int i, int x){
    if(x == 0) return true;
    if(n <= i) return false;
    if(x < 0) return false;
    bool ans1 = call(A, ++i,x - A[i]);
    bool ans2 = call(A, ++i,x);
    return (ans1 || ans2) ? true: false;
}

int main(void){
    cin >> n;
    int A[n];
    for(int i = 0; i < n; ++i) cin >> A[i];
    int x;
    cin >> x;
    if(call(A, 0, x)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}