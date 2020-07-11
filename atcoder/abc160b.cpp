#include <bits/stdc++.h>

using namespace std;

int main(void){
    int sum = 0;
    int x; cin >> x;
    while(true){
        if(0 <= x - 500){
            sum += 1000;
            x -= 500;
        }else {
            break;
        }
    }
    while(true){
        if(0 <= x - 5){
            sum += 5;
            x -= 5;
        }else{
            break;
        }
    }
    cout << sum << endl;
}