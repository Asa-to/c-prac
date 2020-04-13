#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    int maxj = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 0){
            a[i] --;
            maxj = a[i];
            continue;
        }
        if(a[i-1] <= a[i] - 1) a[i] --;
        if(a[i] < maxj){
            cout << "No" << endl;
            return 0;
        }
        maxj = a[i];
    }
    cout << "Yes" << endl;
    return 0;
}