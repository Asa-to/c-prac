#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int A[n];
    bool frag = true;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        if(A[i] % 2 == 0){
            if(A[i] % 3 == 0 || A[i] % 5 == 0){
            }else{
                frag = false;
            }
        }
    }
    if(frag){
        cout << "APPROVED" << endl;
    }else{
        cout << "DENIED" << endl;
    }
    return 0;
}