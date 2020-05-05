#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(i == 0)l[i] = a[i];
        else l[i] = __gcd(l[i-1], a[i]);
    }
    for(int i = n - 1; 0 <= i; i--){
        if(i == n - 1)r[i] = a[i];
        else r[i] = __gcd(a[i], r[i+1]);
    }
    int ans = 1;
    for(int i = 0; i < n; i++){
        if(i == 0)ans = max(ans, r[i+1]);
        else if(i == n-1)ans = max(ans, l[i-1]);
        else ans = max(ans, __gcd(l[i-1], r[i+1]));
    }
    cout << ans << endl;
}