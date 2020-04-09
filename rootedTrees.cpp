#include<bits/stdc++.h>

using namespace std;

struct Node{
    int parent;
    int left;
    int right;
};
struct Node T[100009];
int DepthList[100009];
int nil = -1;

int getDepth(int u){
    int depth = 0;
    while( T[u].parent != nil){
        u = T[u].parent;
        depth++;
    }
    return depth;
}

void setDepth(int u, int depth){
    DepthList[u] = depth;
    if(T[u].left != nil){
        setDepth(T[u].left, ++depth);
    }
    if(T[u].right != nil){
        setDepth(T[u].right, depth);
    }
}

void printChildlen(int u){
    int child = T[u].left;
    cout << "[";
    while(child != nil){
        cout << child;
        if(T[child].right != nil){
            cout << ", ";
        }
        child = T[child].right;
    }
    cout << "]";
}

string getType(int u){
    return getDepth(u) == 0 ? "root" : T[u].left == nil ? "leaf" : "internal node";
}

void printData(int u){
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << getDepth(u) << ", ";
    cout << getType(u) << ", ";
    printChildlen(u);
    cout << endl;
}

int main(void){
    int n;
    cin >> n;
    int id, k;
    for(int i = 0; i < n; i++){
        T[i].parent = T[i].left = T[i].right = nil;
    }
    for(int i = 0; i < n; i++){
        cin >> id >> k;
        for(int j = 0; j < k; j++){
            int child, temp;
            cin >> child;
            if( j == 0) T[id].left = child;
            else T[temp].right = child;
            temp = child;
            T[temp].parent = id;
        }
    }
    for(int i = 0; i < n; i++){
        if(T[i].parent == nil){
            setDepth(i, 0);
            break;
        }
    }
    for(int i = 0; i < n; i++){
        printData(i);
    }
    return 0;
}