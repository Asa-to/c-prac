#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> d(n+1);
    vector<int> f(n+1);
    vector<bool> ok(n+1);
    vector<queue<int> > a(n+1);
    //入力
    for(int i = 0; i < n; i++){
        int num, temp;
        cin >> num >> temp;
        for(int j = 0; j < temp; j++){
            int t;
            cin >> t;
            a[num].push(t);
        }
    }
    //深さ優先探索
    stack<int> date;
    date.push(1);
    int time = 1;
    while(date.size()){
        int now = date.top();
        //nowに始めてきたなら、タイムスタンプを押して訪問済みにする
        if(!ok[now]){
            d[now] = time;
            ok[now] = true;
        }
        //nowからいける頂点を調べる
        while(!a[now].empty()){
            //次の頂点に行ったことがあれば、頂点リストから消す
            if(ok[a[now].front()]){
                a[now].pop();
                continue;
            }
            //次の頂点が決まったら、dateにプッシュする
            date.push(a[now].front());
            break;
        }
        //訪問時の処理が終わったのでtimeをインクリメント
        time++;
        //次の頂点が無ければ探索終了のタイムスタンプを押す
        if(a[now].empty()){
            f[now] = time;
            date.pop();
        }
        //dateが無くなったときにまだ見探索エリアがあれば、そこに行く。
        if(date.empty()){
            for(int i = 1; i <= n; i++){
                if(!ok[i]){
                    date.push(i);
                    break;
                }
            }
            //このままだと1からたどった最後のノードの終了時間と次の開始時間が同じになるので、時間を進める
            time++;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
    return 0;
}