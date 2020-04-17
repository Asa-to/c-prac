#include<bits/stdc++.h>

using namespace std;

//いつか頑張る
int n, pos = 0;
vector<int> pre(100);
vector<int> in(100);
vector<int> post(100);

void call(){
    int root = pre[pos++];
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> pre[i];
    for(int i = 0; i < n; i++)cin >> in[i];
}