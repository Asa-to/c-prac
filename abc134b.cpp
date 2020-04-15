#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, d;
    cin >> n >> d;
    int ans = 0;
    while(0 < n){
        n -= d*2+1;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}