#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    long long sum = 0;
    for(int i = 0; i < n - k; i++){
        sum += h[i];
    }
    cout << sum << endl;
    return 0;
}