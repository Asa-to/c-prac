#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a < b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b){a = b; return true;}return false;}

int main(void){
    int a = 5, b = 3;
    cout << ceil((double)a / b) << endl;
    cout << (a + b - 1) / b << endl;
}