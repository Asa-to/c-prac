#include <bits/stdc++.h>

using namespace std;

int S[100000];
int baai = 0;

void rec(int i, int n){
    if(i == n){
        for(int i = 0; i < n; i++){
            cout << S[i] << " ";
        }
        cout << endl;
        baai ++;
        return;
    }

    S[i] = 1;
    rec(i + 1, n);
    S[i] = 0;
    rec(i + 1, n);
}

void makeConbination(int A[], int n){
    for(int i = 0; i < n; i++) S[i] = 0;
    rec(0, n);
}

int main(void){
    int n; cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) A[i] = 100;
    makeConbination(A, n);
    cout << baai << endl;
    return 0;
}