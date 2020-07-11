#include<bits/stdc++.h>

using namespace std;

bool isKaibun(string s, int begin, int end){
    bool flag = true;
    while(begin < end){
        if(s[begin] == s[end]){

        }else{
            flag = false;
            break;
        }
        begin ++;
        end --;
    }
    return flag;
}

int main(void){
    string S;
    cin >> S;
    int n = S.length();
    if(isKaibun(S, 0, n-1) && isKaibun(S, 0 , (n-1) / 2 - 1) && isKaibun(S, (n + 3) / 2 - 1, n - 1)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}