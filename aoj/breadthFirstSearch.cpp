#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<vector<int> > a(n+1);
    for(int i = 1; i <= n; i++){
        int id, size;
        cin >> id >> size;
        a[i].resize(size);
        for(int j = 0; j < size; j++){
            int temp;
            cin >> temp;
            a[i][j] = temp;
        }
    }
    vector<int> d(n+1);
    vector<bool> ok(n+1);
    queue<int> s;
    s.push(1);
    ok[1] = true;
    while(!s.empty()){
        int now = s.front();
        s.pop();
        for(int i = 0; i < a[now].size(); i++){
            int next = a[now][i];
            if(!ok[next]){
                d[next] = d[now] + 1;
                s.push(next);
                ok[next] = true;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(d[i] == 0)d[i] = -1;
    }
    for(int i = 1; i <= n; i++){
        cout << i << " " << d[i] << endl;
    }
    return 0;
}