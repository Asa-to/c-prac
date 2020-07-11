#include<bits/stdc++.h>

using namespace std;

int fivo(int n, vector<int> memo){
    if(n == 0)return 0;
    if(n == 1)return 1;
    if(memo[n] != 0)return memo[n];
    return memo[n] = fivo(n-1, memo) + fivo(n-2, memo);
}

int main(void){
    int n;
    cin >> n;
    vector<int> memo(n);
    fivo(n, memo);
    cout << memo[n] << endl;
}