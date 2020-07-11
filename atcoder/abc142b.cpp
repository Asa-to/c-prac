#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += k <= a[i] ? 1 : 0;
    }
    cout << sum << endl;
    return 0;
}