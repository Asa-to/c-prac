#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    int left = -1, right = n+1;
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        left = max(left,l);
        right = min(right, r);
    }
    int ans = (right - left) < 0 ? 0 : right - left + 1; 
    cout << ans << endl;
    return 0;
}