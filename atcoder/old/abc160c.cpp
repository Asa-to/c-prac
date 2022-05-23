#include <bits/stdc++.h>

using namespace std;

int main(void){
    int K,N; cin >> K >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    int maxj = abs(K + A[0] - A[N-1]);
    for(int i = 1; i < N; i++){
        maxj = max(maxj, abs(A[i] - A[i-1]));
    }
    cout << K - maxj << endl;
    return 0;
}