#include<bits/stdc++.h>
//覚えた気がする^~

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<vector<int> > m(n+1, vector<int>(n+1));
    vector<int> p(n+1);
    for(int i = 1; i <= n; i++){
        cin >> p[i-1] >> p[i];
    }
    for(int l = 2; l <= n; l++){
        for(int i =1; i <= n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = (1<<21);
            for(int k = i; k <= j - 1; k++){
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]);
            }
        }
    }
    cout << m[1][n];
    return 0;
}