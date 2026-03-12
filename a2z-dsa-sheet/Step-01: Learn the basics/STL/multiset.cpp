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

// multiset -> sorted only, not unique. Contains duplicate elements
void maruf(int t){
    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);

    for(auto i : ms){
        cout << i << " ";
    }
    cout << endl;

    ms.erase(2); // erase all 2
    for(auto i : ms){
        cout << i << " ";
    }
    cout << endl;

    // only a single one erased
    ms.insert(1);
    cout << "Before Erase: " << endl;
    for(auto i : ms){
        cout << i << " ";
    }
    cout << endl;
    ms.erase(ms.find(1));
    cout << "After Erase: " << endl;
    for(auto i : ms){
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