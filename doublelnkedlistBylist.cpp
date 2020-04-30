#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    list<int> a;
    while(n--){
        string command;
        cin >> command;
        if(command == "insert"){
            int u;
            cin >> u;
            a.push_front(u);
        }else if(command == "delete"){
            int u;
            cin >> u;
            for(auto i = a.begin(); i != a.end(); i++){
                if(*i == u){
                    a.erase(i);
                    break;
                }
            }
        }else if(command == "deleteFirst"){
            a.pop_front();
        }else{
            a.pop_back();
        }
    }
    list<int>::iterator it;
    for(it = a.begin(); it != --a.end(); it++)cout << *it << " ";
    cout << *it << endl;
    return 0;
}