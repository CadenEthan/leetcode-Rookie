/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */
#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0; // If needle is empty, return 0
        if(haystack.size() < needle.size()) return -1; // If haystack
        for(int i = 0; i <= haystack.size() - needle.size(); i++) {
            if(haystack.substr(i, needle.size()) == needle) {
                return i; // If the substring matches needle, return the index
            }
        }
        return -1; // If needle is not found, return -1
    }
};
// @lc code=end

