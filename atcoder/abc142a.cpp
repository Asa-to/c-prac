#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    double ans = n % 2 == 0 ? n/2 / (double)n: (n/2+1) / (double)n;
    cout << fixed << setprecision(10) <<  ans << endl;
    return 0;
}