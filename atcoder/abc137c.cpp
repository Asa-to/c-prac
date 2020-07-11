#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    string s;
    map<string, long long> memo;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        sort(s.begin(), s.end());
        if(memo.count(s) == 0){
            memo.insert(make_pair(s,1));
        }else{
            int temp = memo.at(s)++;
            sum += temp;
        }
    }
    cout << sum << endl;
    return 0;
}