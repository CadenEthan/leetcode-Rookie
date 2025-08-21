/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // value -> index
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                vector<int> res;
                res.push_back(num_map[complement]);
                res.push_back(i);
                return res;
                // return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return {}; // Return an empty vector if no solution is found
    }
};
// @lc code=end

