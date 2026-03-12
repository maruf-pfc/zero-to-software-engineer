// In the name of Allah, Most Merciful
// Written by: Md. Maruf Sarker
// Problem Link: 
// Date: 2025-07-23

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
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);

    cout << q.back() << endl;
    q.back() += 5;
    cout << q.back() << endl;

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    cout << q.empty() << endl;
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) maruf(i);
}