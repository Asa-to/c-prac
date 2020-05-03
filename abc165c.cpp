#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(q);
    vector<int> b(q);
    vector<int> c(q);
    vector<int> d(q);
    for(int i = 0; i < q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    int ans = 0;
    for(int bit = 0; bit < m; bit++){
        vector<int> A(n);
        int firstBit = -1;
        for(int i = 0; i < m; i++){
            if((bit & (1 << i))){
                A[i] = i+1;
                if(firstBit == -1){
                    for(int j = 0; j < i; j++){
                        A[j] = A[i];
                    }
                    firstBit = i;
                }
            }else{
                if(firstBit == -1)A[i] = 0;
                else A[i] = A[i-1];
            }
        }
        int sum = 0;
        for(int i = 0; i < q; i++){
            if(A[b[i]-1] - A[a[i]-1] == c[i])sum += d[i];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}