#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    string s;
    cin >> n >> s;
    int sum = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(j <= i) break;
            for(int k = j+1; k < n; k++){
                if(k <= j) break;
                if(s[i] != s[j] && s[j] != s[k] && s[k] != s[i]){
                    if(j - i != k -j){
                        sum++;
                    }
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}