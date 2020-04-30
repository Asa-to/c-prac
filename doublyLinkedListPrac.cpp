#include<bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    Node* p;
    Node* c;
};

Node* nil;
Node* first = nil;

void myinsert(int a){
    Node* u = (Node*)new Node;
    u -> key = a;
    u -> p = nil;
    u -> c = nil;
    if(first == nil){
        first = u;
        return;
    }
    first -> p = u;
    u -> c = first;
    first = u;
}

void call(Node* x){
    if(x -> p == nil && x -> c == nil){
        first = nil;
    }else if(x -> p != nil  && x -> c != nil){
        x -> p -> c = x -> c;
        x -> c -> p = x -> p;
    }else if(x -> p != nil){
        x -> p -> c = nil;
    }else{
        x -> c -> p = nil;
        first = x -> c;
    }
    free(x);
}

void mydelete(int a){
    Node* x = first;
    if(x == nil)return;
    while(x != nil){
        if(x -> key == a){
            call(x);
            return;
        }
        x = x -> c;
    }
}

void deleteFirst(){
    if(first == nil)return;
    call(first);
}

void deleteLast(){
    Node* x = first;
    if(x == nil)return;
    while(x -> c != nil){
        x = x -> c;
    }
    call(x);
}

void print(){
    Node* u = first;
    if(u == nil)return;
    while(u -> c != nil){
        cout << u -> key << " ";
        u = u -> c;
    }
    cout << u -> key << endl;
}

int main(void){
    int n;
    cin >> n;
    while(n--){
        char command[10];
        command[6] = 'a';
        scanf("%s", command);
        if(command[0] == 'i'){
            int a;
            scanf("%d", &a);
            myinsert(a);
        }else if(command[6] == 'L'){
            deleteLast();
        }else if(command[6] == 'F'){
            deleteFirst();
        }else{
            int a;
            scanf("%d", &a);
            mydelete(a);
        }
    }
    print();
}