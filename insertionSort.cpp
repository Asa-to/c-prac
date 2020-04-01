#include <bits/stdc++.h>

using namespace std;

void printHairetu(int A[], int size){
    cout << A[0];
    if(size > 0)for(int i = 1; i < size; i++){cout << " " <<  A[i];}
    cout << endl;
}
int main(void){
    int A;cin >> A;
    int N[A];
    for(int i = 0; i < A; i++) cin >> N[i];
    printHairetu(N, A);
    for(int i = 1; i < A; i++){
        int temp = N[i];
        for(int j = 0; j < i; j++){
            if(temp < N[j]){
                temp = N[j];
                N[j] = N[i];
                N[i] = temp;
            }
        }
        printHairetu(N, A);
    }
}