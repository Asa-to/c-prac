#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int N, M;
    cin >> N >> M;
    vector<bool> seat(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a; b--;
        bool frag = true;
        int now = b;
        for(int i = 0; i < a; i++){
            if(seat[now]) frag = false;
            if(now == N - 1)now = 0;
            else now++;
        }
        if(frag){
            now = b;
            for(int i = 0; i < a; i++){
                seat[now] = true;
                if(now == N - 1)now = 0;
                else now++;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < N; i++){
        if(seat[i]){
            sum++;
        }
    }
    cout << sum << endl;
}