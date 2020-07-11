#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    long double ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans += (double)1 / a[i];
    }
    cout << fixed << setprecision(10) << (double)1 / ans << endl;
    return 0;
}