#include <bits/stdc++.h>

using namespace std;

stack<int> n;

void getNums(int *a, int *b){
    *a = n.top();
    n.pop();
    *b = n.top();
    n.pop();
}

int main(void){
    int a, b;
    string s;
    while(cin >> s){
        if(s == "+"){
            getNums(&a, &b);
            n.push(a+b);
        }else if(s == "-"){
            getNums(&a, &b);
            n.push(b-a);
        }else if(s == "*"){
            getNums(&a, &b);
            n.push(a*b);
        }else{
            n.push(atoi(s.c_str()));
        }
    }
    cout << n.top() << endl;
}