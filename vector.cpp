#include<iostream>
#include<vector>
using namespace std;
int main() {
     vector<int> v;
     v.push_back(2);
     v.push_back(7);
     v.push_back(45);
     for(int i=0;i<v.size();i++)
     cout<<v[i];
 return 0; }