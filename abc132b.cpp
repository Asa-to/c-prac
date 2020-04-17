#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i = 1; i < n-1; i++){
        if(a[i] != min(a[i-1],min(a[i],a[i+1])) && a[i] != max(a[i],max(a[i-1],a[i+1]))){
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}