#include <bits/stdc++.h>

using namespace std;

struct Test{
  vector<int> unko;
  Test* next;
};

Test* nil;

int main(void){
  auto p = (Test*)malloc(sizeof(Test));
  nil = (Test*)malloc(sizeof(Test));
  vector<pair<int, Test*> > tinko;
  tinko.push_back(make_pair(0, p));
  p -> unko.push_back(3);
  cout << p -> unko.at(p -> unko.size() - 1) << endl << p -> unko.size();
  cout << "yes!" << endl;
  return 0;
}