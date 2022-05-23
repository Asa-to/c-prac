#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 1;
    for(int i = 0; i < n; i++){
        set<int> dic;
        dic.insert(a[i]);
        for(int j = i + 1; j < n; j++){
            if(dic.count(a[j]) != 0)break;
            dic.insert(a[j]);
            ans = max(ans, (int)dic.size());
        }
    }
    cout << ans << endl;
}