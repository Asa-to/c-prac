#include <bits/stdc++.h>

using namespace std;

int findMax(int A[], int left, int right){
    int mid = (left + right) / 2;
    if(right - left == 0) return A[mid];
    if(right - left == 1) return max(A[left], A[right]);
    return max(findMax(A, left, mid), findMax(A, mid, right));
}

int main(void){
    int n; cin >> n;
    int A[n]; for(int i = 0; i < n; i++) cin >> A[i];
    cout << "max is " << findMax(A, 0, n - 1) << endl;
    return 0;
}