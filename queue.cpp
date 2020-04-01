#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, q; cin >> n >> q;
    queue<pair<string, int> > data;
    int erapsedTime = 0;
    vector<pair<string, int> > ans;
    for(int i = 0; i < n; i++){
        string name;int time;cin >> name >> time;
        data.push(make_pair(name,time));
    }
    while(!data.empty()){
        if(data.front().second <= q){
            erapsedTime += data.front().second;
            ans.push_back(make_pair(data.front().first, erapsedTime));
            data.pop();
        }else{
            erapsedTime += q;
            data.front().second -= q;
            data.push(data.front());
            data.pop();
        }
    }
    for(auto temp: ans){
        cout << temp.first << " " << temp.second << endl;
    }
}