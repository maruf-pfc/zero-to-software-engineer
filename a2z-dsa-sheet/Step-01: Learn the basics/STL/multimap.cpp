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

// multimap -> duplicate keys + sorted order
void maruf(int t){
    multimap<int, string> mm;

    // Inserting values (including duplicate keys)
    mm.insert({1, "one"});
    mm.insert({2, "two"});
    mm.insert({2, "second two"});
    mm.insert({3, "three"});

    cout << "All elements in multimap:\n";
    for (auto& [key, value] : mm) {
        cout << key << " => " << value << '\n';
    }

    // Finding a specific key
    auto it = mm.find(2);
    if (it != mm.end()) {
        cout << "\nFirst element with key 2: " << it->first << " => " << it->second << '\n';
    }

    // Getting range of elements with the same key
    cout << "\nAll elements with key 2:\n";
    auto range = mm.equal_range(2);
    for (auto itr = range.first; itr != range.second; ++itr) {
        cout << itr->first << " => " << itr->second << '\n';
    }

    // Erase all elements with key 2
    mm.erase(2);

    cout << "\nAfter erasing key 2:\n";
    for (auto& [key, value] : mm) {
        cout << key << " => " << value << '\n';
    }
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) maruf(i);
}