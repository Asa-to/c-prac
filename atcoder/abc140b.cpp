#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int c[n];c[0] = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 1; i < n; i++) cin >> c[i];
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += b[a[i]-1];
        if(0 < i && a[i] == a[i-1]+1) sum += c[a[i]-1];
    }
    cout << sum << endl;
    return 0;
}