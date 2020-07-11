#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int a[n];
    int x[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        x[a[i]-1] = i;
    }
    for(int i = 0; i < n-1; i++){
        cout << x[i]+1 << " ";
    }
    cout << x[n-1]+1 << endl;
    return 0;
}