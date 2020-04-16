#include<bits/stdc++.h>

using namespace std;

struct Node{
    int parent = -1;
    int left = -1;
    int right = -1;
};

Node tree[26];
int depthes[26];
int heights[26];

int getSibiling(int id){
    if(tree[id].parent == -1) return -1;
    return tree[tree[id].parent].left == id ? tree[tree[id].parent].right : tree[tree[id].parent].left;
}

int getDeg(int id){
    int ans = 0;
    if(tree[id].left != -1) ans++;
    if(tree[id].right != -1) ans++;
    return ans;
}

void setDepth(int id, int depth){
    depthes[id] = depth;
    if(tree[id].left != -1)setDepth(tree[id].left, depth+1);
    if(tree[id].right != -1) setDepth(tree[id].right, depth+1);
}

int setHeight(int id){
    int r = 0, l = 0;
    if(tree[id].left == -1 && tree[id].right == -1)return 0;
    if(tree[id].left != -1) l = setHeight(tree[id].left);
    if(tree[id].right != -1) r = setHeight(tree[id].right);
    return heights[id] = 1 + max(r,l);
}

int getRoot(){
    for(int i = 0; i < 26; i++){
        if(tree[i].parent == -1)return i;
    }
    return -1;
}

string getType(int id){
    return tree[id].parent == -1 ? "root" : tree[id].left == -1 && tree[id].right == -1 ? "leaf" : "internal node";
}

/*
void print(int id){
    cout << "node " << id << ": " ;
    cout << "parent = " << tree[id].parent << ", ";
    cout << "sibling = " << getSibiling(id) << ", ";
    cout << "degree = " << getDeg(id) << ", ";
    cout << "depth = " << depthes[id] << ", ";
    cout << "height = " << heights[id] << ", ";
    cout << getType(id) << endl;
}
*/

void print(int id){
    printf("node %d: ", id);
    printf("parent = %d, ",tree[id].parent);
    printf("sibling = %d, ", getSibiling(id));
    printf("degree = %d, ",getDeg(id));
    printf("depth = %d, ",depthes[id]);
    printf("height = %d, ", heights[id]);
    printf("%s\n",getType(id).c_str());
}

int main(void){
    int n, id;
    cin >> n;
    tree[0].parent = -1;
    for(int i = 0; i < n; i++){
        cin >> id >> tree[id].left >> tree[id].right;
        tree[tree[id].left].parent = id;
        tree[tree[id].right].parent = id;
    }
    int root = getRoot();
    setDepth(root,0);
    setHeight(root);
    for(int i = 0; i < n; i++){
        print(i);
    }
    cout << endl;
    return 0;
}