#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 0; i <= n; i++){
        if(i % 3 == 0 || i % 5 == 0){

        }else{
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}