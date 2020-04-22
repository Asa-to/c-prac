#include<bits/stdc++.h>

using namespace std;

int parent(int i){
    return i/2;
}

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}

int main(void){
    int h;
    cin >> h;
    int a[h+1];
    for(int i = 1; i <= h; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= h; i++){
        cout << "node " << i <<": ";
        cout << "key = " << a[i] << ", ";
        if(parent(i) >= 1)cout << "parent key = " << a[parent(i)] << ", ";
        if(left(i) <= h)cout << "left key = " << a[left(i)] << ", ";
        if(right(i) <= h)cout << "right key = " << a[right(i)] << ", ";
        cout << endl;
    }
    return 0;
}