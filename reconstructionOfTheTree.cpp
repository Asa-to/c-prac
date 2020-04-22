#include<bits/stdc++.h>

using namespace std;

vector<int> pre(1000);
vector<int> in(1000);
vector<int> post;
int rootPoint = 0;

int getNext(){
    return pre[rootPoint++];
}

int findInin(int c){
    return distance(in.begin(), find(in.begin(), in.end(), c));
}

void print(){
    for(int i = 0; i < post.size(); i++){
        if(i){
            cout << " ";
        }
        cout << post[i];
    }
    cout << endl;
}

void reconstruction(int l, int r){
    if(l >= r){
        return;
    }
    int root = getNext(); // preorderの次の節店
    int m = findInin(root); // inorderにおけるrootの位置
    reconstruction(l,m);
    reconstruction(m + 1,r);

    post.push_back(root);
}

int main(void){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> pre[i];
    }
    for(int i = 0; i < n; i++){
        cin >> in[i];
    }
    reconstruction(0,n);
    print();
    return 0;
}