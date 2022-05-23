#include<bits/stdc++.h>

using namespace std;

int main(void){
    int k;
    cin >> k;
    k++;
    long long sum = 0;
    int temp = 0;
    int memo[300][300];
    for(int i = 0; i <= 200; i++){
        for(int j = 0; j <= 200; j++){
            memo[i][j] = -1;
        }
    }
    for(int a = 1; a < k; a++){
        for(int b = 1; b < k; b++){
            for(int c = 1; c < k; c++){
                if(memo[a][b] == -1){
                    memo[a][b] = __gcd(a, b);
                }
                if(memo[b][c] == -1){
                    memo[b][c] = __gcd(b, c);
                }
                if(memo[a][memo[b][c]] == -1){
                    memo[a][memo[b][c]] = __gcd(a, memo[b][c]);
                }
                sum += memo[a][memo[b][c]];
            }
        }
    }
    cout << sum << endl;
    return 0;
}