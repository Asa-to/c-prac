#include<bits/stdc++.h>

using namespace std;

/*解法
* s[i] != s[j] !=  s[k]を満たし、j-i != k-jを満たす組の数は、
* R,G,Bそれぞれの個数をr,g,bとしたときの積rgbから、1つめの条件を満たして2詰めの条件を満たさない(2*j == k+i)要素数を引けば求められる。
*/

int main(void){
    int n;
    string s;
    cin >> n >> s;
    long long R = 0, G = 0, B =0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            R++;
        }else if(s[i] == 'G'){
            G++;
        }else if(s[i] == 'B'){
            B++;
        }
    }
    long long sum = R * G * B;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int k = 2 * j - i;
            if(k >= n) continue;
            if (s[i] != s[j] && s[j] != s[k] && s[i] != s[k]) sum--;
        }
    }
    cout << sum << endl;
    return 0;
}