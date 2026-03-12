// In the name of Allah, Most Merciful
// Written by: Md. Maruf Sarker
// Problem Link: 
// Date: 2025-07-22

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
    int n; 
    cout << "Enter the value of n: " << flush;
    cin >> n;

    for(int i = 1; i <= n; i++){
        // space
        for(int j = 1; j <= n - i; j++){
            cout << " ";
        }
        // star
        for(int j = 1; j <= 2 * i - 1; j++){
            cout << "*";
        }
        // space
        for(int j = 1; j <= n - i; j++){
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) maruf(i);
}