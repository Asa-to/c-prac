#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m;
    cin >> n;
    set<int> data;
    for(int i = 0; i < n; i++){
        cin >> m;
        if(data.count(m)){
            cout << "NO" << endl;
            return 0;
        }
        data.insert(m);
    }
    cout << "YES" << endl;
    return 0;
}