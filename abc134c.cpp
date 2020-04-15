#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, point, maxj = -1;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        maxj = max(maxj, a[i]);
        if(maxj == a[i]) point = i;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(i == point){
            cout << a[n-2] << endl;
        }else{
            cout << a[n-1] << endl;
        }
    }
    return 0;
}