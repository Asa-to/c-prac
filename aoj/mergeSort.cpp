#include <bits/stdc++.h>

using namespace std;

int A[500900];
int sum = 0;

void merge(int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    for(int i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = 1010009000;
    R[n2] = 1100009000;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++){
        sum ++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

int main(void){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    mergeSort(0, n);
    for(int i = 0; i < n-1; i++){
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl <<  sum << endl;
    return 0;
}