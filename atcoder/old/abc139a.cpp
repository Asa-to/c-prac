#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s, t;
    cin >> s >> t;
    int sum = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == t[i]) sum++;
    }
    cout << sum << endl;
    return 0;
}
