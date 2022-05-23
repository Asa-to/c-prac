#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n-1);
    int sum = 0;
    for(int i = 0; i < n-1; i++){
        cin >> a[i];
        if( i == 0){
            sum += a[i];
        }else{
            sum += min(a[i], a[i-1]);
        }
    }
    cout << sum + a[n-2] << endl;
    return 0;
}