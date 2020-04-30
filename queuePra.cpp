#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, q;
    cin >> n >> q;
    queue<pair<string, int> > m;
    for(int i = 0; i < n; i++){
        string name;
        int time;
        cin >> name >> time;
        m.push(make_pair(name, time));
    }
    int time = 0;
    while(!m.empty()){
        pair<string, int> now = m.front();
        m.pop();
        if(now.second <= q){
            time += now.second;
            cout << now.first << " " << time << endl;
        }else{
            time += q;
            now.second -= q;
            m.push(now);
        }
    }
    return 0;
}