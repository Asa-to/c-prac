#include<bits/stdc++.h>

using namespace std;

int n;

int partition(int A[], int a, int b){
    int x = A[b];
    //こうしないと、jがbを超える恐れがある
    int j = a-1;
    for(int i = a; i < b; i++){
        if(A[i] <= x){
            ++j;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    A[b] = A[j+1];
    A[j+1] = x;
    return ++j;
}

void quickSort(int A[], int a, int b){
    if(a < b){
        //a ~ cまでの要素は、c ~ bまでの要素より小さいことが分かっているので、cは次のソートには用いない
        int c = partition(A, a, b);
        quickSort(A, a, c-1);
        quickSort(A, c+1, b);
    }
}

int main(void){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    quickSort(A, 0, n-1);
    for(auto i: A){
        cout << i << " ";
    }
}