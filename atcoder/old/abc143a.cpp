#include<bits/stdc++.h>

using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;
    int ans = a - b * 2;
    ans = ans < 0 ? 0 : ans;
    cout << ans << endl;
    return 0;
}