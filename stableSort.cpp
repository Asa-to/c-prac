#include <bits/stdc++.h>

using namespace std;

void print(string A[], int size){
    cout << A[0];
    if(size > 1)for(int i = 1; i < size; i++)cout << " " << A[i];
    cout << endl;
}

int main(void){
    int N; cin >> N;
    string cards[N];
    string bubbleCards[N];
    for(int i = 0; i < N; i++){
      cin >> cards[i];
      bubbleCards[i] = cards[i];
    }
    bool frag = true;
    while(frag){
        frag = false;
        for(int i = 1; i < N; i++){
            if(bubbleCards[i-1][1] > bubbleCards[i][1]){
                string temp = bubbleCards[i];
                bubbleCards[i] = bubbleCards[i-1];
                bubbleCards[i-1] = temp;
                frag = true;
            }
        }
    }
    print(bubbleCards, N);
    cout << "Stable" << endl;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(cards[minj][1] > cards[j][1]){
                minj = j;
            }
        }
        string temp = cards[minj];
        cards[minj] = cards[i];
        cards[i] = temp;
    }
    print(cards, N);
    bool isStable = true;
    for(int i = 0; i < N; i++){
        if(cards[i] != bubbleCards[i]){
            isStable = false;
            break;
        }
    }
    string ans = isStable? "Stable" : "Not stable";
    cout << ans << endl;
    return 0;
}    