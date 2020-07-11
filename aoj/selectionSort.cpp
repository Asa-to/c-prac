#include <bits/stdc++.h>

using namespace std;

int main(void){
    int N; cin >> N;
    int A[N];
    for(int i = 0; i < N; i++)cin >> A[i];
    int numOfChange = 0;
    for(int i = 0; i < N; i ++){
        int minNum = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minNum]) minNum = j;
        }
        if(i != minNum){
            int temp = A[i];
            A[i] = A[minNum];
            A[minNum] = temp;
            numOfChange ++;
        }
    }
    cout << A[0];
    if(1 < N)for(int i = 1; i < N; i++)cout << " " << A[i];
    cout << endl << numOfChange << endl;
}