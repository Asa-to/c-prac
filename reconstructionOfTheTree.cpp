#include<bits/stdc++.h>

using namespace std;

int n, root;
int pre[100], in[100], post[100];

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> pre[i];
    for(int i = 0; i < n; i++)cin >> in[i];
    root = pre[0];
}