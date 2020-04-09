#include <bits/stdc++.h>

using namespace std;

struct Tree{
    int parent = -1;
    int childlen[100009];
    int numOfChild = 0;
};

vector<Tree> Nodes(1000);

int getDepth(int n){
    int depth = 0;
    struct Tree now = Nodes[n];
    while(now.parent != -1){
        depth++;
        now = Nodes[now.parent];
    }
    return depth;
}

string getType(int n){
    return getDepth(n) == 0 ? "root" : Nodes[n].numOfChild == 0 ? "leaf" : "internal node";
}

void printData(int n){
    cout << "node " << n << ": ";
    cout << "parent = " << Nodes[n].parent <<", ";
    cout << "depth = " << getDepth(n) << ", ";
    cout << getType(n) << ", ";
    cout << "[";
    for(int i = 0; i < Nodes[n].numOfChild; i++){
        if(i + 1 < Nodes[n].numOfChild){
            cout << Nodes[n].childlen[i] << ", ";
        }else{
            cout << Nodes[n].childlen[i];
        }
    }
    cout << "]" << endl;
}

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int id, k;
        cin >> id >> k;
        if(0 < k){
            Nodes[id].numOfChild += k;
            for(int j = 0; j < k; j++){
                int child;
                cin >> child;
                Nodes[id].childlen[j] = child;
                Nodes[child].parent = id;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printData(i);
    }
    return 0;
}