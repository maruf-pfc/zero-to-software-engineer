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

// unordered map -> unique + randomize
void maruf(int t){
    unordered_map<int, string> ump;

    // Insertion using [] operator
    ump[1] = "one";
    ump[2] = "two";

    // Insertion using insert
    ump.insert({3, "three"});
    ump.insert(make_pair(4, "four"));

    // Insertion using emplace
    ump.emplace(5, "five");

    // Accessing values
    cout << "All elements in unordered_map:\n";
    for (auto& [key, value] : ump) {
        cout << key << " => " << value << '\n';
    }

    // Find an element
    auto it = ump.find(3);
    if (it != ump.end()) {
        cout << "\nFound key 3: " << it->first << " => " << it->second << '\n';
    } else {
        cout << "\nKey 3 not found\n";
    }

    // Check if a key exists
    if (ump.count(2)) {
        cout << "\nKey 2 exists in map\n";
    }

    // Erase a key
    ump.erase(4);

    // After erase
    cout << "\nAfter erasing key 4:\n";
    for (auto& [key, value] : ump) {
        cout << key << " => " << value << '\n';
    }

    // Size of map
    cout << "\nSize of unordered_map: " << ump.size() << '\n';

    // Clear the map
    ump.clear();
    cout << "Size after clearing: " << ump.size() << '\n';
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) maruf(i);
}