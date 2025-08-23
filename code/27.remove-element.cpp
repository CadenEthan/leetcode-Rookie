/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int write_index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[write_index] = nums[i];
                write_index++;
            }
        }
        return write_index; // Return the new length of the array
    }
};
// @lc code=end
