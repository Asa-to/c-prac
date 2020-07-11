#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s;
    cin >> s;
    map<char,int> a;
    bool flag = true;
    for(int i = 0; i < 4; i++){
        if(a.count(s[i]) == 0){
            a.insert(make_pair(s[i], 1));
        }else{
            if(a.at(s[i]) == 1){
                a.at(s[i])++;
            }else{
                flag = false;
            }
        }
    }
    if(flag && a.size() == 2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}