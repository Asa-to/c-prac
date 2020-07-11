#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int R[n];
    int minj = 1000000009;
    int maxprofit = -2147483648;
    for(int i =0; i < n; i++){
        cin >> R[i];
        if(i > 0)maxprofit = max(maxprofit, R[i] - minj);
        minj = min(minj, R[i]);
    }
    cout << maxprofit << endl;
    return 0;
}

/*
for(int i = 0; i  < n; i++){
        for(int j = i+1; j < n; j++){
            maxprofit = max(maxprofit, R[j] -R[i]);
        }
    }
*/