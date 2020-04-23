#include<bits/stdc++.h>

using namespace std;

int main(void){
	multiset<int> a = {1,1,1,1,1,1};
	cout << *(--a.end()) << endl;
}