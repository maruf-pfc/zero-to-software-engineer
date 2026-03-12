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
    map<int, int> mp;
    map<int, pair<int, int>> mp1;
    map<pair<int, int>, int> mp2;

    mp[1] = 2;
    mp.insert({3, 1});
    mp.emplace(4, 10);
    mp.insert({2, 4});
    mp2[{2, 3}] = 10;

    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }

    cout << mp[1] << endl; // 2
    cout << mp[2] << endl; // 4

    auto it = mp.find(3);
    cout << it->second << endl;

    map<int, string> mpp;
    mpp[1] = "one";
    mpp[3] = "three";
    mpp[5] = "five";

    auto it1 = mpp.lower_bound(2);  // Finds first element >= 2 → (3, "three")
    auto it2 = mpp.upper_bound(3);  // Finds first element > 3 → (5, "five")

    if (it1 != mpp.end())
        cout << "Lower bound of 2: " << it1->first << " -> " << it1->second << endl;
    else
        cout << "Lower bound not found\n";

    if (it2 != mpp.end())
        cout << "Upper bound of 3: " << it2->first << " -> " << it2->second << endl;
    else
        cout << "Upper bound not found\n";

}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) maruf(i);
}