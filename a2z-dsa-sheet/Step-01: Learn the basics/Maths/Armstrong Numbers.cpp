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
  // 371 = 3^3 + 7^3 + 1^3 = 371
  int n = 371;
  int sum = 0;
  int original = n;
  while(n){
    int rem = n % 10;
    sum += (rem * rem * rem);
    n /= 10;
  }

  cout << (original == sum ? "YES" : "NO") << endl;
}

int main() {
  Maruf
  int t = 1;
  // cin >> t;
  for(int i = 1; i <= t; i++) maruf(i);
}