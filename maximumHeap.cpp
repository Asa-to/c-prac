#include<bits/stdc++.h>

using namespace std;

vector<int> a;

int left(int a){
    return 2*a;
}

int right(int a){
    return 2*a+1;
}

int parent(int a){
    return a/2;
}

void maxHeapify(int i){
    int l = left(i);
    int r = right(i);
    //左の子、右の子、自分の中で値が最大のノードを選ぶ
    int largest = distance(a.begin(),find(a.begin(), a.end(),max(a[i], max(a[l], a[r]))));
    if(largest != i){
        swap(a[largest], a[i]);
        maxHeapify(largest);
    }
}

void buildMaxHeap(){
    for(int i = a.size()/2; 0 < i; i--){
        maxHeapify(i);
    }
}

int main(void){
    int n;
    cin >> n;
    a.push_back(0);
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }
    buildMaxHeap();
    a.erase(a.begin());
    for(auto i: a){
        cout << " " << i;
    }
    cout << endl;
    return 0;
}