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

// Custom comparator
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;

    // If second values are equal, sort by first in descending order
    return p1.first > p2.first;
}

void maruf(int t) {
    // Sample array and vector
    int a[] = {5, 3, 1, 4, 2};
    int n = 5;
    vector<int> v = {5, 3, 1, 4, 2};

    // Normal sorting
    sort(a, a + n);
    sort(v.begin(), v.end());

    // Partial sort
    sort(a + 2, a + 4); // Sorts a[2], a[3]

    // Descending order sort using built-in comparator
    sort(a, a + n, greater<int>());

    // Custom comparator sort
    pair<int, int> arr[] = {
        {1, 2},
        {2, 1},
        {4, 1}
    };
    sort(arr, arr + 3, comp); // array size is 3

    // Expected Output:
    // {4, 1}, {2, 1}, {1, 2}

    // __builtin_popcount for integers
    int num1 = 7;
    int cnt1 = __builtin_popcount(num1); // Count of 1s in binary
    cout << "7 has " << cnt1 << " set bits" << endl;

    // __builtin_popcountll for long long integers
    long long num2 = 75342573273234532;
    int cnt2 = __builtin_popcountll(num2);
    cout << num2 << " has " << cnt2 << " set bits" << endl;

    // next_permutation
    string s = "123";
    sort(s.begin(), s.end()); // must need to sort the array to get all the permutations
    cout << "All permutations of 123:\n";
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    /*
    All permutations of 123:
        123
        132
        213
        231
        312
        321
    */

    // max_element and min_element
    int maxElement = *max_element(v.begin(), v.end());
    int minElement = *min_element(v.begin(), v.end());

    cout << "Max element in vector: " << maxElement << endl;
    cout << "Min element in vector: " << minElement << endl;
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) maruf(i);
}