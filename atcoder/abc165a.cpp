#include<bits/stdc++.h>

using namespace std;

int main(void){
    int k, a, b;
    cin >> k >> a >> b;
    bool ok = false;
    for(int i = 1; i <= b; i++){
        if(a <= k * i && k * i <= b)ok = true;
    }
    if(ok){
        cout << "OK" << endl;
    }else{
        cout << "NG" << endl;
    }
}