#include<bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> a){
    for(int i = 0; i < a.size(); i++){
        if(a[i] != i+1) return false;
    }
    return true;
}

int main(void){
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> point;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        if(a[i] != i+1){
            point.push_back(i);
        }
    }
    if(point.size() == 2)swap(a[point[0]], a[point[1]]);
    if(isSorted(a)){
        cout <<"YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}