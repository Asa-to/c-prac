#include<bits/stdc++.h>

using namespace std;

int main(void){
    long long x;
    cin >> x;
    long long a = 100;
    long long i;
    for(i = 0; a < x; i++){
        a += (double)a * 0.01;
    }
    cout << i << endl;
}