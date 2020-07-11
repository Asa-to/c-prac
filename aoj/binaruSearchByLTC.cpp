#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n; cin >> n;
    int S[n];
    for(int i = 0; i < n; i++) cin >> S[i];
    int q; cin >> q;
    int T[q];
    for(int i = 0; i < q; i++) cin >> T[i];

    int sum = 0;
    for(int i = 0; i < q; i++){
        if(*lower_bound(S, S+n, T[i]) == T[i]){
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}