#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;
    vector<bool> ok(n, false);
    for(int i = 0; i < k; i++){
        int d;
        cin >> d;
        for(int j = 0; j < d; j++){
            int a;
            cin >> a;
            ok[a-1] = true;
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(!ok[i]){
            sum++;
        }
    }
    cout << sum << endl;
}