#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, x;
    cin >> n >> x;
    int l[n];
    for(int i = 0; i < n; i++)cin >> l[i];
    int sum = 1, now = 0;
    for(int i = 0; i < n; i++){
        now += l[i];
        if (now <= x) sum++;
    }
    cout << sum << endl;
    return 0;
}