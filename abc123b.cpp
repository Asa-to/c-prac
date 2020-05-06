#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    int n = 5;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    int point = 0;
    int minj = 9;
    for(int i = 0; i < n; i++){
        if(a[i] % 10 == 0)continue;
        if(chmin(minj, a[i] % 10)){
            point = i;
        }
    }
    swap(a[point], a[4]);
    int order = 0, next = 0;
    int time;
    for(time = 0; ; time++){
        if(order == 0 && next == 5)break;
        if(order == 0 && time % 10 == 0){
            order += a[next++];
        }
        if(0 < order){
            order--;
        }
    }
    cout << time << endl;
}