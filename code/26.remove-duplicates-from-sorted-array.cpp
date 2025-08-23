/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include<istream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // If the array is empty, return 0
        int write_index = 1; // Index to write the next unique element
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) { // If the current element is different from the previous one
                nums[write_index] = nums[i]; // Write it to the write_index
                write_index++; // Move the write_index forward  
            }
        }
        return write_index;
    }
};
// @lc code=end

