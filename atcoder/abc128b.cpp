#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<pair<pair<string, int>, int> > a(n+1);
    for(int i = n; 1 <= i; i--){
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
        a[i].first.second *= -1;
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <= n; i++){
        cout << a[i].second << endl;
    }
    return 0;
}