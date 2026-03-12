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
  int n1 = 9, n2 = 12;
  int gcd = 1, hcf = 0;
  
  for(int i = 1; i <= min(n1, n2); i++){
    if(n1 % i == 0 and n2 % i == 0){
      gcd = i;
    }
  }

  cout << "GCD = " << gcd << endl;

  // way 2 = Euclidean ALgorithm
  while(n1 and n2){
    if(n1 > n2) n1 %= n2;
    else n2 %= n1;
  }

  if(n1 == 0) cout << "GCD = " << n2 << endl;
  else cout << "GCD = " << n1 << endl;
}

int main() {
  Maruf
  int t = 1;
  // cin >> t;
  for(int i = 1; i <= t; i++) maruf(i);
}