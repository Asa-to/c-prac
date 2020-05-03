#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    vector<stack<int> > bro(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        bro[s].push(t);
        bro[t].push(s);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool ok = true;
        while(bro[i].size()){
            int b = bro[i].top();
            bro[i].pop();
            if(h[i] <= h[b])ok = false;
        }
        if(ok)ans++;
    }
    cout << ans << endl;
}