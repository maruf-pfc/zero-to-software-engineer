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
  int n = 7789;
  int res = 0;
  
  while(n){
    int r = n % 10;
    n /= 10;
    res = (res * 10) + r;
  }

  cout << res << endl;
}

int main() {
  Maruf
  int t = 1;
  // cin >> t;
  for(int i = 1; i <= t; i++) maruf(i);
}