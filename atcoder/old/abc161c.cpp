#include<bits/stdc++.h>

using namespace std;

int main(void){
    long long n, k;
    cin >> n >> k;
    //nがkの倍数なら、答えは0
    if(n % k == 0){
        cout << 0 << endl;
        return 0;
    }
    long long minj = n % k;
    minj = min(minj, k - minj);
    cout << minj << endl;
    return 0;
}