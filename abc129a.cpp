#include<bits/stdc++.h>

using namespace std;

int main(void){
    int p, q, r;
    cin >> p >> q >> r;
    int sum = q + p + r - max(q,max(p, r));
    cout << sum << endl;
    return 0;
}