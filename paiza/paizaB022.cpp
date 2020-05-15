#include<bits/stdc++.h>

using namespace std;

int main(void){
    int m, n, k;
    cin >> m >> n >>k;
    int a[k];
    vector<int> sum(m+1,0);
    int maxj = 0;
    for(int i = 0; i < k; i++){
        cin >> a[i];
        if(n > 0){
            n--;
            sum[a[i]]++;
        }
        for(int j = 0; j < sum.size(); j++){
            if(j == a[i]) continue;
            if(sum[j] > 0){
                sum[j]--;
                sum[a[i]]++;
            }
        }
    }
    for(int i = 0; i < sum.size(); i++) maxj = max(maxj, sum[i]);
    for(int i = 0; i < sum.size(); i++){
        if(sum[i] == maxj){
            cout << i << endl;
        }
    }
    return 0;
}