#include<bits/stdc++.h>

using namespace std;

int myPow(int n){
    int ans = 1;
    for(int i = 0; i < n; i++){
        ans *= 10;
    }
    return ans;
}

int main(void){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if(a < b){
        for(int i = 0; i < b; i++){
            ans += a * myPow(i);
        }
    }else{
        for(int i = 0; i < a; i++){
            ans += b * myPow(i);
        }
    }
    cout << ans << endl;
    return 0;
}
