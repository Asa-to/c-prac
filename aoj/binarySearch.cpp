#include <bits/stdc++.h>

using namespace std;

bool binarySearch(int A[], int key, int sita, int top){
    int mid;
    while( sita < top){
        mid = (sita + top) / 2;
        if(A[mid] == key)return true;
        if(A[mid] < key){ sita = mid + 1;}
        else{ top = mid;}
    }
    return false;
}

int main(void){
    int n; cin >> n;
    int S[n]; for(int i = 0; i < n; i++) cin >> S[i]; 
    int q; cin >> q;
    int T[q]; for(int i = 0; i < q; i++) cin >> T[i];
    int sum = 0;
    for(int i = 0; i < q; i++){
        if(binarySearch(S, T[i], 0, n))sum++;
    }
    cout << sum << endl;
}