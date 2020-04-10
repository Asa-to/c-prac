#include<bits/stdc++.h>

using namespace std;

int main(void){
    int h, a;
    cin >> h >> a;
    int sum = 0;
    while(0 < h){
        h = h -a;
        sum ++;
    }
    cout << sum << endl;
    return 0;
}