#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, l;
    cin >> n >> l;
    int diff = 1000000, sum = 0, point;
    for(int i = 1; i < n+1; i++){
        if(abs(l+i-1) < diff){
            diff = abs(l+i-1);
            point = i;
        }
        sum += l+i-1;
    }
    diff = l+point-1;
    cout << (sum)-(diff) << endl;
    return 0;
}