#include<bits/stdc++.h>

using namespace std;

int n, d;

double call(vector<double> a, vector<double> b, int j){
    if(d <= j) return 0;
    double sum = call(a, b, j+1);
    return sum += pow(a[j] - b[j], 2);
}

double getDit(vector<double> a, vector<double> b){
    double sum = call(a, b, 0);
    return sqrt(sum);
}

void print(vector<double> a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(void){
    cin >> n >> d;
    vector<vector<double> > a(n, vector<double>(d));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            double dis = getDit(a[i], a[j]);
            int t = (int)dis;
            if(dis == (double)t) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}