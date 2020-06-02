#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    string s;
    cin >> s;
    bool frag = true;
    if(s[0] != 'A')frag = false;
    int countC = 0;
    for(int i = 2; i < s.length() - 1; i++){
        if(s[i] == 'C'){
            countC++;
            s[i] = 'c';
        }
    }
    if(countC != 1)frag = false;
    for(int i = 1; i < s.length(); i++){
        if((int)s[i] < (int)'a' | (int)'z' < (int)s[i])frag = false;
    }
    if(frag)cout << "AC" << endl;
    else cout << "WA" << endl;
}