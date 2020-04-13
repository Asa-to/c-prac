#include<bits/stdc++.h>

using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;
    int sum = 1;
    int ans = 0;
    while(sum < b){
        sum += a - 1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}