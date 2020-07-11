#include<bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    Node *parent;
    Node *left;
    Node *right;
};

Node *nil, *root;

void find(int a){
    Node *x = root;
    bool flag = false;
    while(x != nil){
        if(x->key == a)flag = true;
        if(a < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    if(flag){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}

void insert(int a){
    Node *x = root;
    Node *y = nil; //xの親
    Node *z = (Node*)malloc(sizeof(Node));
    z->key = a;
    z->left = nil;
    z->right = nil;

    //zの親に適切なNodeを指定する
    while(x != nil){
        y = x;
        //根の値より大きいかどうかで根の位置をずらしていく。小さければ左。
        if(z->key < x->key){
            x = x->left; 
        }else if(x->key < z->key){
            x = x->right;
        }
    }
    z->parent = y;

    if(y == nil){
        root = z;
    }else if(z->key < y->key){
        y->left = z;
    }else{
        y->right = z;
    }
}

vector<int> in;
void inorder(Node *n){
    if(n == nil)return;
    inorder(n->left);
    in.push_back(n->key);
    inorder(n->right);
}

vector<int> pre;
void preorder(Node *n){
    if(n == nil)return;
    pre.push_back(n->key);
    preorder(n->left);
    preorder(n->right);
}

Node* getNode(int key){
    //aをkeyに持つ要素xを探す
    Node *x = root;
    while(x != nil){
        if(x->key == key)break;
        if(x->key < key){
            x = x->right;
        }else{
            x = x->left;
        }
    }
    return x;
}

// Node* getSuccessor(Node *x){
//     inorder(root);
//     Node *a = getNode(in[distance(in.begin(),find(in.begin(), in.end(), x->key))+1]);
//     in.clear();
//     return a;
// }

Node* getTreeMinmum(Node *x){
    while(x->left != nil){
        x = x->left;
    }
    return x;
}

Node* getSuccessor(Node *x){
    if(x->right != nil){
        return getTreeMinmum(x->right);
    }
    Node *y = x->parent;
    while(y != nil && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

void deletej(Node *x){
    //削除対象を節点yとする
    Node *y;
    if(x->left == nil || x->right == nil){
        y = x;
    }else{
        y = getSuccessor(x);
    }
    //yの子zを決める
    Node *z;
    if(y->left != nil){
        z = y->left;
    }else{
        z = y->right;
    }
    //zの親を設定する
    if(z != nil){
        z->parent = y->parent;
    }
    //yが根だったら、rootをxにする
    //根じゃなかったら、yの親の子にzを設定する
    if(y->parent == nil){
        root = x;
    }else if(y->parent->left == y){
        y->parent->left = z;
    }else{
        y->parent->right = z;
    }
    //xの次節点を削除した場合、yのキーをxにコピーする
    if(y != x){
        x->key = y->key;
    }
    free(y);
}

void print(){
    inorder(root);
    for(int i = 0; i < in.size(); i++){
        cout << " " << in[i];
    }
    cout << endl;
    preorder(root);
    for(int i = 0; i < pre.size(); i++){
        cout << " " << pre[i];
    }
    cout << endl;
    pre.clear();
    in.clear();
}

int main(void){
    int n;
    cin >> n;
    while(n--){
        string command;
        cin >> command;
        if(command == "insert"){
            int a;
            cin >> a;
            insert(a);
        }else if(command == "find"){
            int a;
            cin >> a;
            find(a);
        }else if(command == "delete"){
            int a;
            cin >> a;
            deletej(getNode(a));
        }else{
            print();
        }
    }
}