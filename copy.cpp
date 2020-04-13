#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int a=0,b=0,c=0;
 
    for(int i = 0; i < n; i++){
        if(s[i]=='R'){
            a++;
        }else if(s[i]=='G'){
            b++;
        }else{
            c++;
        }
    }
    // ひとつめの条件をみたす
    int res = a*b*c;
 
    // ひとつめ満たすけど、ふたつめの条件をみたさないものは引く
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int k=j+j-i;
            if(k>=n) continue;
            if(s[i]!=s[j] && s[j]!=s[k] && s[k]!=s[i]){
                res--;
            }
        }
    }
    cout << res << endl;
    return 0;
}