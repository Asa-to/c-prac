#include<bits/stdc++.h>

using namespace std;

int main(void){
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    long long g = c*d/__gcd(c,d);
    cout << fixed << setprecision(0) << b - b/c - b/d + b/g - (a-1 - (a-1)/c - (a-1)/d + (a-1)/g) << endl;
    return 0;
}