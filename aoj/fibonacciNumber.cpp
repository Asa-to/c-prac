#include<bits/stdc++.h>

using namespace std;

int fiv(int a[], int n){
    if(a[n])return a[n];
    if(n == 0)return a[n] = 1;
    if(n == 1)return a[n] = 1;
    return a[n] = fiv(a, n-1) + fiv(a, n-2);
}

int main(void){
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 0; i <= n; i++)a[i] = 0;
    fiv(a, n);
    cout << a[n] << endl;
}