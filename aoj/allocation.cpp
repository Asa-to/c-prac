#include <bits/stdc++.h>

using namespace std;

int howManyMount(long long p,int w[], int size){
    long long sum = 0;
    int k = 1;
    for(int i = 0; i < size; i++){ 
        if(sum + w[i] <= p){
            sum += w[i];
        }else{
            if(p < w[i]) return 900000;
            sum = w[i];
            k++;
        }
    }
    return k;
}

int solve(int k,int w[], int size){
    long long right = 10000000000;
    long long left = 0;
    long long mid = 0;
    int temp;
    while(left + 1 < right){
        mid = (right + left) / 2;
        temp = howManyMount(mid, w, size);
        if(k < temp){
            left = mid;
        }else{
            right = mid;
        }
    }
    return right;
}

int main(void){
    int n, k; cin >> n >> k;
    int w[n];
    for(int i = 0; i < n; i++) cin >> w[i];
    cout << solve(k,w,n) << endl;
    return 0;
}