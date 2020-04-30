#include<bits/stdc++.h>

using namespace std;

stack<int> num;

void add(){
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    num.push(a+b);
}

void sub(){
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    num.push(b-a);
}

void mul(){
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    num.push(a * b);
}

int main(void){
    string s;
    while(cin >> s){
        if(s == "+"){
            add();
        }else if(s == "-"){
            sub();
        }else if(s == "*"){
            mul();
        }else{
            num.push(stoi(s));
        }
    }
    cout << num.top() << endl;
}