#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, x;
    while(true){
        cin >> n >> x;
        if(x + n == 0)break;
        int sum = 0;
        for(int i = 1; i <= n - 2; i++){
            for(int j = i + 1; j <= n - 1; j++){
                for(int k = j + 1; k <= n; k++){
                    if(i + j + k == x)sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}