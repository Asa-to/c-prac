#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    string command, str;
    cin >> n;
    set<string> dic;
    for(int i = 0; i < n; i++){
        cin >> command >> str;
        if(command == "insert"){
            dic.insert(str);
        }else{
            if(dic.find(str) != dic.end())cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}