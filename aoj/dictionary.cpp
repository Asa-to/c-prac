#include <bits/stdc++.h>

using namespace std;

#define M 1046527

vector<long long> date(M, -1);

int h1(long long key){ return key % M;}

int h2(long long key){ return 1 + (key % (M - 1));}

int h(long long key, int i){ return h1(key) + i * h2(key) % M;}


long long getInt(string str){
    long long sum = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'A') sum += 1 * pow(10,i);
        if(str[i] == 'C') sum += 2 * pow(10,i);
        if(str[i] == 'G') sum += 3 * pow(10,i);
        if(str[i] == 'T') sum += 4 * pow(10,i);
    }
    return sum;
}

//keyの入っていた場所を返す。入ってなければ-1を返す。
int find(long long key){
    int num;
    for(int i = 0; ; i++){
        num = h(key, i);
        if(date[num] == -1){
            return -1;
        }else if(date[num] == key){
            return num;
        }
    }
}

//keyとiをhashした場所にkeyがあればtrueを返す
bool find(long long key, int i){
    int num = h(key, i);
    if(date[num] == -1) return false;
    if(date[num] == key) return true;
    return false;
}


void insert(long long key){
    if(find(key) == -1){
        for(int i = 0;; i++){
            if(date[h(key, i)] == -1) date[h(key, i)] = key;
            break;
        }
    }
}

int main(void){
    long long n; cin >> n;
    string command, value;
    long long key;
    for(long long i = 0; i < n; i++){
        cin >> command >> value;
        key = getInt(value);
        if(command == "insert"){
            insert(key);
        }else{
            if(find(key) != -1){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}