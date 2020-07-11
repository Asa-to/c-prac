#include <bits/stdc++.h>

using namespace std;

int solve(int A[], int i, int m, int n){
    if(m == 0) return 1;
    if(m < 0) return 0;
    if(n <= i) return 0;
    int u = solve(A, i+1, m - A[i], n);
    int y = solve(A, i+1, m, n);
    return max(u,y);
}

int main(void){
    int n; cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    int q; cin >> q;
    int m[q];
    for(int i = 0; i < q; i++) cin >> m[i];
    for(int i = 0; i < q; i++){
        if(solve(A, 0, m[i], n)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}