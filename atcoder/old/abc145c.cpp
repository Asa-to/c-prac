#include<bits/stdc++.h>

using namespace std;

double getDis(pair<int, int> a, pair<int, int> b){
    double xv = a.first - b.first;
    double yv = a.second - b.second;
    return pow(xv * xv + yv * yv, 0.5);
}

int main(void){
    int n;
    cin >> n;
    vector<pair<int, int> > pos(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        pos[i] = make_pair(x, y);
    }
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        x[i] = i;
    }
    double dis = 0;
    int kumi = 0;
    do{
        kumi++;
        for(int i = 0; i < n-1; i++){
            dis += getDis(pos[x[i]], pos[x[i+1]]);
        }
    }while(next_permutation(x.begin(), x.end()));
    dis /= kumi;
    cout << fixed << setprecision(10) <<  dis << endl;
    return 0;
}