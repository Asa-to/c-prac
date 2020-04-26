#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    set<string> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(m.count(s) == 0)m.insert(s);
    }
    cout << m.size() << endl;
}