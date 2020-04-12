#include<bits/stdc++.h>

using namespace std;

int main(void){
    long long n;
    cin >> n;
    long long ans = n+1;
    for(long long i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            if(i == 1){
                ans = min(ans, n-1);
            }else{
                ans = min(ans, n/i + i - 2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}