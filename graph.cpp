#include<bits/stdc++.h>

using namespace std;

void print(vector<vector<int> > a){
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < a[0].size(); j++){
            cout << a[i][j];
            if(j + 1 < a[0].size())cout << " ";
        }
        cout << endl;
    }
}

int main(void){
    int n;
    cin >> n;
    vector<vector<int> > a(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++){
        int k, l;
        cin >> k >> l;
        for(int j = 1; j <= l; j++){
            int temp;
            cin >> temp;
            a[i][temp] = 1;
        }
    }
    print(a);
    return 0;
}
