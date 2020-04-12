#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    bool ans = false;
    if(n % 10 == 7){
        cout << "Yes" << endl;
        return 0;
    }
    n /= 10;
    if(n % 10 == 7){
        cout << "Yes" << endl;
        return 0;
    }
    n /= 10;
    if( n == 7){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}