#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> a;
    a.push(s[0]);
    for(int i = 1; i < n; i++){
        if(a.top() != s[i]){
            a.push(s[i]);
        }
    }
    cout << a.size() << endl;
    return 0;
}