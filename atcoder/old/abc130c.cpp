#include<bits/stdc++.h>

using namespace std;

int main(void){
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    double ans = w * h * 0.5;
    cout << fixed << setprecision(10) << ans << " ";
    if(x == w/2 && y == h / 2){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}