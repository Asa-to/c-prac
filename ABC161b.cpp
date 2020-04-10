#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    double A[n];
    double sum = 0;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        sum += A[i];
    }
    double ander = sum / (4 * m);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(A[i] >= ander){
            ans++;
        }
    }
    if(ans >= m){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}