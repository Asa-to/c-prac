#include<bits/stdc++.h>

using namespace std;

int x[10][10];

bool check(int n){
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            if(x[i][j] == n) return true;
        }
    }
    return false;
}

int main(void){
    int n;
    cin >> n;
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            x[i][j] = i * j;
        }
    }
    if(check(n)){
        cout << "Yes" <<endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}