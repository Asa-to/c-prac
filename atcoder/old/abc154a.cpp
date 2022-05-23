#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s, t, u;
    int n,m;
    cin >> s >> t >> n >> m >> u;
    if(s == u){
        n--;
    }else{
        m--;
    }
    cout << n << " " << m << endl;
    return 0;
}