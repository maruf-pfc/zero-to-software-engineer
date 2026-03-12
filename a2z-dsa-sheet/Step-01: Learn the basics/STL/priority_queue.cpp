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

// push -> O(logn)
// pop -> O(1)
void maruf(int t){
    // Priority Queue by default Maximum Heap
    priority_queue<int> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.emplace(5);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> mhpq;
    mhpq.push(4);
    mhpq.push(65);
    mhpq.emplace(32);
    
    while (!mhpq.empty()) {
        cout << mhpq.top() << " ";
        mhpq.pop();
    }
    cout << endl;
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) maruf(i);
}