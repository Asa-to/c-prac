#include<bits/stdc++.h>

using namespace std;

int main(void){
    long long l, r;
    cin >> l >> r;
    long long minj = 2020;
    for(l; l < r; l++){
        for(int j = r; l < j; j--){
            minj = min(minj, l*j%2019);
            if(minj == 0){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << minj << endl;
    return 0;
}