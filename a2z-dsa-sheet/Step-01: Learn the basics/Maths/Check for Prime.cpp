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
  int n = 19;
  int cnt = 0;

  for(int i = 1; i <= n; i++){
    if(n % i == 0){
      cnt++;
    }

    if(cnt == 2){
      cout << "YES" << endl;
    }
  }

  // way 2
  cnt = 0;
  for(int i = 1; i * i <= n; i++){
    if(n % i == 0){
      cnt++;
      if((n / i) != i){
        cnt++;
      }
    }
  }

  cout << (cnt == 2 ? "YES" : "NO") << endl;
}

int main() {
  Maruf
  int t = 1;
  // cin >> t;
  for(int i = 1; i <= t; i++) maruf(i);
}