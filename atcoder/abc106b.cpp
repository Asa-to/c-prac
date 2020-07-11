#include<bits/stdc++.h>

using namespace std;

int check(int a){
    int sum = 1;
    for(int i = 1; i < a / 2; i++){
        if(a % i == 0){
            sum++;
        }
    }
    return sum == 8 ? 1 : 0;
}

int main(void){
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 11; i <= n; i += 2){
        sum += check(i);
    }
    cout << sum << endl;
    return 0;
}