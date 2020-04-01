#include <bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    Node *prev, *next;
};

Node *nil;

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil -> next = nil;
    nil -> prev = nil;
}

void insert(int key){
    Node *x = (Node *)malloc(sizeof(Node));
    x -> key = key;
    x -> next = nil -> next;
    x -> next -> prev = x;
    x -> prev = nil;
    nil -> next = x;
}

Node* listSearch(int key){
    Node *sercher = nil->next;
    while(key != sercher->key && sercher != nil){
        sercher = sercher->next;
    }
    return sercher;
}

void deleteNode(Node *del){
    if(del == nil)return;
    del->prev->next = del->next;
    del->next->prev = del->prev;
    free(del);
}

void deleteKey(int key){
    deleteNode(listSearch(key));
}

void deleteFirst(){
    deleteNode(nil->next);
}

void deleteLast(){
    deleteNode(nil->prev);
}

void printNode(){
    Node *print = nil->next;
    cout << print->key;
    print = print->next;
    while(print != nil){
        cout << " " << print->key;
        print = print->next;
    }
    cout << endl;
}

int main(void){
    int n; cin >> n;
    string command;
    init();
    for(int i = 0; i < n; i++){
        cin >> command;
        if(command == "insert"){
            int value; cin >> value;
            insert(value);
        }else if(command == "delete"){
            int value; cin >> value;
            deleteKey(value);
        }else if(command == "deleteFirst"){
            deleteFirst();
        }else if(command == "deleteLast"){
            deleteLast();
        }else{}
    }
    printNode();
}