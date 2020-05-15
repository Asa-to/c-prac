#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}
char black = '0';
int white = '1';

int main(void){
    string sWhite;
    cin >> sWhite;
    string tBlack = sWhite;
    int fBlack, fWhite;
    if(sWhite[0] == white){
        fWhite = 0;
        fBlack = 1;
        tBlack[0] = black;
    }else{
        fWhite = 1;
        fBlack = 0;
        sWhite[0] = white;
    }
    int len = sWhite.length();
    for(int i = 1; i < len; i++){
        if(sWhite[i] == sWhite[i-1]){
            if(sWhite[i] == white){
                sWhite[i] = black;
            }else{
                sWhite[i] = white;
            }
            fWhite++;
        }
        if(tBlack[i] == tBlack[i-1]){
            if(tBlack[i] == white){
                tBlack[i] = black;
            }else{
                tBlack[i] = white;
            }
            fBlack++;
        }
    }
    cout << min(fWhite, fBlack) << endl;
}