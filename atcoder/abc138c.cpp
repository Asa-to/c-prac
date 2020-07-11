#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<double> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n-1; i++){
        a[i+1] = (a[i] + a[i+1])/2;
    }
    cout << fixed << setprecision(10) << a[n-1] << endl;
    return 0;
}