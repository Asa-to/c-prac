#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, sum = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        sum += temp;
    }
    if(sum <= n){
        cout << n-sum << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}