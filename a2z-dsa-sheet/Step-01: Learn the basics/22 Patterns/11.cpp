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
#define Maruf                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution{
public:
};

int flip(int i){
    return (i == 1 ? 0 : 1);
}

void maruf(int t){
    int n;
    cout << "Enter the value of n: " << flush;
    cin >> n;

    int start = -1;
    for (int i = 0; i < n; i++){
        if(i % 2 == 0) start = 1;
        else start = 0;

        for(int j = 0; j <= i; j++){
            cout << start;
            start = flip(start);
        }
        cout << endl;
    }
}

int main(){
    Maruf int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) maruf(i);
}