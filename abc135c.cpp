#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> monsters(n+1);
    vector<int> b(n);
    for(int i = 0; i < n+1; i++) cin >> monsters[i];
    for(int i = 0; i < n;i++) cin >> b[i];
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int panch;
        panch = min(b[i], monsters[i]);
        b[i] -= panch;
        ans += panch;
        panch = min(b[i], monsters[i+1]);
        b[i] -= panch;
        ans += panch;
        monsters[i+1] -= panch;
    }
    cout << ans << endl;
    return 0;
}