/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include<iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) { // Check if prefix is not a prefix of strs[i]
                prefix = prefix.substr(0, prefix.size() - 1); // Reduce the prefix
                if (prefix.empty()) return ""; // If prefix becomes empty, return ""
            }
        }
        return prefix; // Return the longest common prefix found
    }
};
// @lc code=end

