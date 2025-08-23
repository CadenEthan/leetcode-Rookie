/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                    return false;
                char top = stack.top();
                stack.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '['))
                {
                    return false; // Mismatched parentheses
                }
            }
        }
        return stack.empty(); // If stack is empty, all parentheses are matched
    }
};
// @lc code=end
