#include <bits/stdc++.h>

using namespace std;

int main(void){
    int N; cin >> N;
    int A[N];
    for(int i = 0; i < N; i++){cin >> A[i];}
    bool frag = true;
    int numOfChanged = 0;
    while(frag){
        frag = false;
        for(int i = N-1; 0 < i; i--){
            if(A[i] < A[i-1]){
                int temp = A[i];
                A[i] = A[i-1];
                A[i-1] = temp;
                frag = true;
                numOfChanged ++;
            }
        }
    }
    cout << A[0];
    for(int i = 1; i < N; i++){
        cout <<" " << A[i];
    }
    cout << numOfChanged << endl;
}