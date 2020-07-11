#include<bits/stdc++.h>

using namespace std;

struct Node{
    int parent = -1;
    int left = -1;
    int right = -1;
};

Node tree[26];

void preorder(int id){
    cout << " " << id;
    if(tree[id].left != -1)preorder(tree[id].left);
    if(tree[id].right != -1)preorder(tree[id].right);
}

void inorder(int id){
    if(tree[id].left != -1)inorder(tree[id].left);
    cout << " " << id;
    if(tree[id].right != -1)inorder(tree[id].right);
}

void postOrder(int id){
    if(tree[id].left != -1)postOrder(tree[id].left);
    if(tree[id].right != -1)postOrder(tree[id].right);
    cout << " " << id;
}

int getRoot(){
    for(int i = 0; i < 26; i++){
       if(tree[i].parent == -1){
           return i;
       }
    }
    return -1;
}

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int id;
        cin >> id >> tree[id].left >> tree[id].right;
        tree[tree[id].left].parent = id;
        tree[tree[id].right].parent = id;
    }
    cout << "Preorder" << endl;
    preorder(getRoot());
    cout << endl << "Inorder" << endl;
    inorder(getRoot());
    cout << endl << "Postorder" << endl;
    postOrder(getRoot());
    return 0;
}