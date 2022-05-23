#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, maxj = 1;
    cin >> n;
    string s;
    map<string, int> mapj;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(mapj.count(s)){
            mapj.at(s)++;
            maxj = max(maxj, mapj.at(s));
        }else{
            mapj.insert(make_pair(s, 1));
        }
    }
    for(map<string, int>::iterator i = mapj.begin(); i != mapj.end(); i++){
        if(i->second == maxj){
            cout << i->first << endl;
        }
    }
    return 0;
}