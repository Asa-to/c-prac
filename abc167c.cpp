#include<bits/stdc++.h>

using namespace std;

int n, m, x;

bool ok(vector<int> a, int x){
    for(int i = 0; i < m; i++){
        if(a[i] < x){
            return false;
        }
    }
    return true;
}

int main(void){
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int> > a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int minj = 10000000;
    //i番目の本を
    for(int bit = 0; bit < (1 << n); bit++){
        vector<int> ans(m);
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(bit & (1 << i)){
                sum += c[i];
                for(int j = 0; j < m; j++){
                    ans[j] += a[i][j];
                }
            }
        }
        bool frag = true;
        for(int i = 0; i < m; i++){
            if(ans[i] < x)frag = false;
        }
        if(frag){
            minj = min(minj, sum);
        }
    }
    if(minj == 10000000){
        minj = -1;
    }
    cout << minj << endl;
}