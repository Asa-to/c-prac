#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, k;
    cin >> n >>k;
    long double ans = 0;
    for(int i = 1; i <= n; i++){
        long double now = i;
        long double score = 1;
        for(int j = 1; now < k; j++){
            now *= 2;
            score /= 2;
        }
        ans += score;
    }
    cout << fixed << setprecision(10) << ans / n << endl;
    return 0;
}