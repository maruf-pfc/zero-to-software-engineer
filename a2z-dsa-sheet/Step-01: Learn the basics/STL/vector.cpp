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

// vector uses singly linked list
void maruf(int t){
    vector<int> v1;

    v1.push_back(1);
    v1.emplace_back(2);
    v1.push_back(3);
    v1.emplace_back(4);
    v1.push_back(5);

    vector<pair<int, int>> vp;
    vp.push_back({1, 2});
    vp.emplace_back(3, 4);

    vector<int> v2(5);
    for(auto i : v2){
        cout << i << sp;
    }
    // 0 0 0 0 0
    cout << endl;

    vector<int> v3(5, 100);
    for(auto i : v3){
        cout << i << sp;
    }
    // 100 100 100 100 100
    cout << endl;

    // vector copy
    vector<int> v4(5, 20);
    vector<int> v5(v4);
    for(auto i : v4){
        cout << i << sp;
    }
    // 20 20 20 20 20
    cout << endl;
    for(auto i : v5){
        cout << i << sp;
    }
    // 20 20 20 20 20
    cout << endl;

    // access values
    cout << v1[0] << " " << v1.at(1) << endl;
    cout << v1.back() << endl;

    // iterator
    vector<int>::iterator it1 = v1.begin();
    cout << *(it1) << endl;
    it1++;
    cout << *(it1) << endl;

    it1 += 2;
    cout << *(it1) << endl;

    vector<int>::iterator it2 = v1.end();
    cout << v1[0] << " " << v1[2] << endl; // 1 3
    cout << v1.back() << endl; // 5

    // print the vector using iterator
    for(vector<int>::iterator it1 = v1.begin(); it1 != v1.end(); it1++){
        cout << *(it1) << " ";
    }
    // 1 2 3 4 5
    cout << endl;

    // shortcut using auto
    for(auto it1 = v1.begin(); it1 != v1.end(); it1++){
        cout << *(it1) << " ";
    }
    // 1 2 3 4 5
    cout << endl;

    // print using auto
    for(auto i : v1){
        cout << i << " ";
    }
    // 1 2 3 4 5
    cout << endl;

    // erase
    v1.erase(v1.begin() + 3);
    for(auto i : v1){
        cout << i << " ";
    }
    // 1 2 3 5
    cout << endl;
    v1.push_back(7);
    for(auto i : v1){
        cout << i << " ";
    }
    // 1 2 3 5 7
    cout << endl;
    v1.erase(v1.begin() + 1, v1.begin() + 3);
    for(auto i : v1){
        cout << i << " ";
    }
    // 1 5 7
    cout << endl;


    // insert function
    vector<int> v(2, 100); // {100, 100}
    v.insert(v.begin(), 300); // {300, 100, 100}
    v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

    // vector copy
    vector<int> copy(2, 50); // {50, 50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    // print size
    v.size(); // 7

    // remove last element
    v.pop_back();

    vector<int>v6 = {10, 20};
    vector<int>v7 = {30, 40};
    cout << v6[0] << " " << v6[1] << endl; // 10 20
    cout << v7[0] << " " << v7[1] << endl; // 30 40

    v6.swap(v7);

    cout << v6[0] << " " << v6[1] << endl; // 30 40
    cout << v7[0] << " " << v7[1] << endl; // 10 20

    // clear vector
    v.clear();

    // check empty or not
    cout << v.empty() << endl; // 1

    v = {1, 2, 3, 4, 5};
    // lower bound and upper bound
    auto it5 = lower_bound(v.begin(), v.end(), 2); // same as st.lower_bound(2)
    auto it6 = upper_bound(v.begin(), v.end(), 3); // same as st.upper_bound(3)

    if (it5 != v.end()) {
        cout << "lower_bound(2): " << *it5 << endl;
    } else {
        cout << "lower_bound(2): not found" << endl;
    }

    if (it6 != v.end()) {
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