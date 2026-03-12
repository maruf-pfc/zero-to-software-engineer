// In the name of Allah, Most Merciful
// Written by: Md. Maruf Sarker
// Problem Link: https://leetcode.com/problems/two-sum/description/
// Date: 2026-03-06

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
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force approach
        // time complexity: O(n^2), space complexity: O(1)
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i + 1; j < nums.size(); j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};

        // optimal approach using hash map
        // time complexity: O(n), space complexity: O(n)
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int sub = target - nums[i];
            if(mp.find(sub) != mp.end()){
                return {mp[sub], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

void maruf(int t){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    for(int i : ans) cout << i << sp;
    cout << endl;
}

int main() {
    Maruf
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) maruf(i);
}