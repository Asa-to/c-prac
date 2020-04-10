#include<bits/stdc++.h>

using namespace std;

int main(void){
    int h, n;
    cin >> h >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(h <= sum + temp){
            cout << "Yes" << endl;
            return 0;
        }else{
            sum += temp;
        }
    }
    cout  << "No" << endl;
    return 0;
}