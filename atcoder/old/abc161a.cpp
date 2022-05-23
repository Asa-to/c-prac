#include<bits/stdc++.h>

using namespace std;

int main(void){
    int a, b, c;
    cin >> a >> b >> c;
    swap(a, b);
    swap(a, c);
    cout << a << " " << b << " " << c << endl;
    return 0;
}