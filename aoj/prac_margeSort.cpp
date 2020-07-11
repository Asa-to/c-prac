#include<bits/stdc++.h>

using namespace std;

#define inf 1000000009;

int n;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1];
    int R[n2+1];
    for(int i = 0; i < n1; i++) L[i] = A[left + i];
    for(int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = inf;
    R[n2] = inf;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right){
    if(right - left > 1){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void){
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    mergeSort(A, 0, n);
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    return 0;
}