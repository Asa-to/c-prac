#include <bits/stdc++.h>

using namespace std;

int main(void){
    string str; cin >> str;
    if(str[2] == str[3] && str[4] == str[5]){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }    
    return 0;
}