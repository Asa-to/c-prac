#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s;
    cin >> s;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]){
            cout << "Bad" << endl;
            return 0;
        }
    }
    cout << "Good" << endl;
    return 0;
}