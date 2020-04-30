#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    if(13 <= n){
        cout << m << endl;
    }else if(6 <= n){
        cout << m/2 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}