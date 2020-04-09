#include <bits/stdc++.h>

using namespace std;

struct Test{
  map<string, int> pasuta;
  int age;
  Test* next;
};

Test* nil = (Test*)malloc(sizeof(Test));

int main(void){
  nil -> age = 100;
  cout << "yes" << endl;
  nil -> pasuta.insert(make_pair("takosu", 13));
  cout << "yes" << endl;
  vector<int> childlen(0);
  return 0;
}