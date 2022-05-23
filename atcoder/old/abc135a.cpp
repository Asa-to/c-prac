#include<bits/stdc++.h>

using namespace std;

int main(void){
    long long A, B;
    cin >> A >> B;
    if((A + B) % 2 == 1){
        cout << "IMPOSSIBLE" << endl;
    }else{
        long long ans = (A + B) / 2;
        cout << ans << endl;
    }
    return 0;
}