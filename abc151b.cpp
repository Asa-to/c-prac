#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, k, m, sum = 0;
    cin >> n >> k >> m;
    vector<int> a(n);
    for(int i = 0; i < n-1; i++){
        cin >> a[i];
        sum += a[i] - m;
    }
    if(m - sum <= 0){
        cout << 0 << endl;
    }else if(k < m - sum){
        cout << -1 << endl;
    }else{
        cout << m - sum << endl;
    }
    return 0;
}