#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    int left = -1;
    int ans = 0;
    int sum = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(left < a[i]){
            sum = 0;
        }else{
            sum++;
        }
        left = a[i];
        ans = max(ans, sum);
        //cout << sum << " " << ans << " " << left << endl;
    }
    cout << ans << endl;
    return 0;
}