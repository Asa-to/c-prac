#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<string> a(n+1, "no");
    vector<int> waNum(n+1, 0);
    int ac = 0, wa = 0;
    for(int i = 0; i < m; i++){
        int num;
        string result;
        cin >> num >> result;
        if(a[num] == "AC") continue;
        if(result == "AC"){
            ac++;
            wa += waNum[num];
        }else{
            waNum[num]++;
        }
        a[num] = result;
    }
    cout << ac << " " << wa << endl;
    return 0;
}