#include<bits/stdc++.h>

using namespace std;

struct Node{
    int parent;
    int right;
    int left;
};

void preorder(Node tree[], int id){
    cout << id << " ";
    if(tree[id].left = -1) return;
    preorder(tree, tree[id].left);
    if(tree[id].right = -1) return;
    preorder(tree, tree[id].right);
}

int main(void){
    int n, id;
    cin >> n;
    Node tree[n];
    tree[n].parent = -1;
    for(int i = 0; i < n; i++){
        cin >> id;
        cin >> tree[id].left >> tree[id].right;
        tree[tree[id].right].parent = id;
        tree[tree[id].left].parent = id;
    }
    cout << "Preorder" << endl;
    preorder(tree,0);
}