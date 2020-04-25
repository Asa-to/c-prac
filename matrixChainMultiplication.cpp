#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> p(n+1);
    for(int i = 0; i < n*2; i++){
        cin >> p[i];
    }
    vector<vector<int> > dp(n+1, vector<int>(n+1));
}