#include<bits/stdc++.h>

using namespace std;

int ansn(int n){
    if(n == 1) return 1;
    return n * ansn(n - 1);
}

int main(void){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    ans += (n * (n-1) / 2) + (m * (m-1) / 2);
    cout << ans << endl;
    return 0;
}