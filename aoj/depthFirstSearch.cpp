#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<queue<int> > a(n+1); 
    //入力
    for(int i = 1; i <= n; i++){
        int id, num;
        cin >> id >> num;
        for(int j = 0; j < num; j++){
            int temp;
            cin >> temp;
            a[i].push(temp);
        }
    }
    vector<int> d(n+1);
    vector<int> f(n+1);
    stack<int> place;
    place.push(1);
    int time = 0;
    while(place.size()){
        int now = place.top();
        //初めて来たらタイムスタンプ
        if(!f[now]){
            f[now] = ++time;
        }
        //次に行く場所を決める
        while(a[now].size()){
            //まずnowの隣接リストから探す
            if(!f[a[now].front()]){
                place.push(a[now].front());
                a[now].pop();
                break;
            }else{
                a[now].pop();
            }
        }
        //nowの隣接リストに見探索の頂点が無ければ一個前に戻る。
        //同時に終了のタイムスタンプを押す
        if(now == place.top()){
            place.pop();
            d[now] = ++time;
        }
        //たどり切ったときに、探索出来ない場所に見探索の頂点があれば次の目的地にする
        if(place.size() == 0){
            for(int i = 1; i <= n; i++){
                if(f[i] == 0){
                    place.push(i);
                    break;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << i << " " << f[i] << " " << d[i] << endl;
    }
    return 0;
}