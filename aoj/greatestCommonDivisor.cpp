#include<bits/stdc++.h>

using namespace std;

int main(void){
    int x, y;
    cin >> x >> y;
    if(x < y){
        int temp = x;
        x = y;
        y = temp;
    }
    if(x != y) x = x % y;
    for(int i = min(x, y); 0 < i; i--){
        if(x % i == 0 && y % i == 0){
            cout << i << endl;
            continue;
        }
    }
    return 0;
}