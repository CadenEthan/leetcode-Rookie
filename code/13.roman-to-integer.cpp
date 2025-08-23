/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        for(char c : s) {
            if (c < 'A' || c > 'Z') {
                return 0; // Invalid character
            }
        }
        int result = 0;
        int prev_value = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            int value = 0;
            switch (s[i]) {
                case 'I': value = 1; break; 
                case 'V': value = 5; break;
                case 'X': value = 10; break;
                case 'L': value = 50; break;
                case 'C': value = 100; break;   
                case 'D': value = 500; break;   
                case 'M': value = 1000; break;
                default: return 0; // Invalid character 
            }
            if (value < prev_value) {
                result -= value; // Subtract if the current value is less than the previous value
            } else {
                result += value; // Add otherwise
            }
            prev_value = value; // Update the previous value
        }
        return result; // Return the final result
    }
};
// @lc code=end

