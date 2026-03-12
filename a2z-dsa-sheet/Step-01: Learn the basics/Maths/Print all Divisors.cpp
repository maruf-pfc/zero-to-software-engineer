// In the name of Allah, Most Merciful
// Written by: Md. Maruf Sarker
// Problem Link: 
// Date: 2025-08-29

#include <bits/stdc++.h>
// #include <debug.h>
using namespace std;

#define ll long long
#define endl "\n"
#define sp " "
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Maruf ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class Solution {
public:
  
};

void maruf(int t){
  int n = 256;

  for(int i = 1; i <= n; i++){
    if(n % i == 0){
      cout << i << " ";
    }
  }

  cout << endl;

  // way 2
  set<int> s;
  for(int i = 1; i * i <= n; i++){
    if(n % i == 0){
      s.insert(i);
      
      if(n / i != i){
        s.insert(n / i);
      }
    }
  }

  for(auto i : s){
    cout << i << " ";
  }

  cout << endl;
}

int main() {
  Maruf
  int t = 1;
  // cin >> t;
  for(int i = 1; i <= t; i++) maruf(i);
}