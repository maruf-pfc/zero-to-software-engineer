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
    // unordered set only contains unique values, not sorted
    // lower bound and upper bound do not work in this case
    // it does not stores in any particular order. It has a better complexity than set in most cases, except some when collision happens

    unordered_set<int> uset;
    uset.insert(5);
    uset.insert(1);
    uset.insert(3);
    uset.insert(2);
    uset.insert(4);
    uset.insert(3); // Duplicate, will not be added again

    for (auto x : uset) {
        cout << x << " ";
    }
    cout << endl;

    /*
        unordered_set is faster (on average) for:

        insert(x)
        find(x)
        erase(x)
        count(x)

        Because they are hash-based, not comparison-based.
    */
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) maruf(i);
}