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

// set = unique + sorted
// set is typically implemented as a balanced binary search tree (Red-Black Tree)
void maruf(int t){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.emplace(0);
    s.insert(5);

    // Functionality of insert in vector can be used also, that only increases efficiency

    // begin(), end(), rbegin(), rend(), size(), empty() and swap() are same as those of above

    for(auto i : s){
        cout << i << " ";
    }
    cout << endl;
    for (auto x : s) {
        auto it = s.find(x);  // returns iterator to x
        cout << x << " at " << &(*it) << endl;
    }
    /*
        0 1 2 4 5 
        0 at 0x614d8066ffc0
        1 at 0x614d8066ff30
        2 at 0x614d8066ff60
        4 at 0x614d8066ff90
        5 at 0x614d8066fff0
    */
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    // 0 1 2 4 5 
    cout << endl;
    
    auto it1 = s.find(4); // memory address
    if (it1 != s.end()) {
        cout << "Value: " << *it1 << ", Address: " << &(*it1) << endl;
    } else {
        cout << "Element 4 not found." << endl;
    }


    int cnt = s.count(1);
    // here sets contains unique values. so if it exists it will return 1 otherwise return 0
    cout << "Count: " << cnt << endl; // 1


    auto it2 = s.find(3); // if not found then return s.end()

    // Case 1: Erase by value
    s.erase(5); // takes logarithmic time

    // Case 2: Erase by iterator
    auto it = s.find(4);
    s.erase(it); // takes constant time

    // Casa 3: Erase by range
    s.erase(s.begin(), s.end()); // takes O(n) time

    set<int> st = {1, 2, 3, 4, 5};
    auto it3 = st.find(2);
    auto it4 = st.find(4);
    st.erase(it3, it4);
    for(auto i : st){
        cout << i << " ";
    }
    // {1, 4, 5}
    cout << endl;

    st.insert(2);
    st.insert(3);

    // lower bound and upper bound same as vector
    auto it5 = st.lower_bound(2);
    auto it6 = st.upper_bound(3);

    if (it5 != st.end()) {
        cout << "lower_bound(2): " << *it5 << endl;
    } else {
        cout << "lower_bound(2): not found" << endl;
    }

    if (it6 != st.end()) {
        cout << "upper_bound(3): " << *it6 << endl;
    } else {
        cout << "upper_bound(3): not found" << endl;
    }
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) maruf(i);
}