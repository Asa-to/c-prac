#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0; i < n - 2; i++){
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C')sum++;
    }
    cout << sum << endl;
    return 0;
}