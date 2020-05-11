#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s, t;
    cin >> s >> t;
    t[t.length() - 1] =  ' ';
    s += ' ';
    if(s == t){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}