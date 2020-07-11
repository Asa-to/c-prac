#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    string s;
    cin >> s;
    int year = stoi(s.substr(0,4));
    int month = stoi(s.substr(5,2));
    int day = stoi(s.substr(8,2));
    if(year < 2019 || year == 2019 && month <= 4){
        cout << "Heisei" << endl;
    }else{
        cout << "TBD" << endl;
    }
}