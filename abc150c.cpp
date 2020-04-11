#include<bits/stdc++.h>

using namespace std;

void print(vector<int> a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int call(vector<int> a){
    int result = 1;
    vector<int> x(a.size());
    for(int i = 0; i < a.size(); i++) x[i] = i+1;
    while(true){
        for(int i = 0; i < a.size(); i++){
            if(x[i] != a[i]) break;
            if(i == a.size() - 1) return result;
        }
        result++;
        next_permutation(x.begin(), x.end());
    }
}

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int av = call(a);
    int bv = call(b);
    cout << abs(av - bv) << endl;
    return 0;
}