#include<bits/stdc++.h>

using namespace std;

int n, m;

long long call(vector<vector<int> > a, int i, int j){
    long long sum = 0;
    for(int now = 0; now < n; now++){
        sum += max(a[now][i], a[now][j]);
    }
    return sum;
}

int main(void){
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    long long sum = 0;
    for(int i = 0; i < m + 1; i++){
        for(int j = i + 1; j < m; j++){
            sum = max(sum, call(a, i, j));
        }
    }
    cout << sum << endl;
}