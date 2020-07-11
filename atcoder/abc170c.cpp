#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b){a = b; return true;}return false;}


int main(void){
    int x, n;
    cin >> x >> n;
    if(n == 0){
        cout << x << endl;
        return 0;
    }
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    sort(a.begin(), a.end());
    auto xp = find(a.begin(), a.end(), x);
    if(xp == a.end()){
        cout << x << endl;
        return 0;
    }
    auto left = xp, right = xp;
    int i = *xp, j = *xp;
    while(true){
        if(i == *left && j == *right){
            if(left != a.begin())left--;
            if(right != a.end())right++;
            i--;
            j++;
            continue;
        }else if(i == *left){
            cout << j << endl;
        }else{
            cout << i << endl;
        }
        return 0;
    }
}