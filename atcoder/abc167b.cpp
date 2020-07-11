#include<bits/stdc++.h>

using namespace std;

int main(void){
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int ans = 0;
    if(a <= k){
        ans += a;
        k -= a;
    }else{
        ans += k;
        k = 0;
    }
    if(b <= k){
        k -= b;
    }else{
        k = 0;
    }
    ans -= k;
    cout << ans << endl;
}