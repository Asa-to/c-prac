#include <bits/stdc++.h>

using namespace std;

struct tree{
    int id;
    int k;
    tree* parent;
    vector<pair<int, tree*> > childlen;
    bool haveChild = false;
};

tree *nil;

int getDepth(tree* p){
    int sum = 0;
    while(p -> parent != nil){
        ++sum;
        p = p -> parent;
    }
    return sum;
}

void printData(tree * p){
    string type = getDepth(p) == 0 ? "root" : p -> haveChild ? "internal node" : "leaf";
    cout << "node " << p -> id << ": parent = " << p -> parent -> id << ", depth = " << getDepth(p) << ", " << type << ", [";
    for(int i = 0; i < p -> k; i++){
        if(i + 1 < p -> k){
            cout << p -> childlen[i].first << ", ";
        }else{
            cout << p -> childlen[i].first;
        }
    }
    cout << "]" << endl;
}

int main(void){
    nil = (tree*)malloc(sizeof(tree));
    int n;
    cin >> n;
    int id, k;
    tree* nodes[n];
    for(int i = 0; i < n; i++){
        tree* p = (tree*)malloc(sizeof(tree));
        p -> id = i;
        nodes[i] = p;
    }
    nodes[0] -> parent = nil;
    tree* now;
    for(int i = 0; i < n; i++){
        now = nodes[i];
        int id, k;
        cin >> id >> k;
        for(int j = 0; j < k; j++){
            now -> haveChild = true;
            int child;
            cin >> child;
            now -> childlen[j] = make_pair(child,nodes[child]);
        }
    }
    for(auto i: nodes){
        printData(i);
    }
    return 0;
}