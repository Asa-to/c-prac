#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 2; i <= n; i++){
        int num;
        cin >> num;
        a[num]++;
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << endl;
    }
    return 0;
}