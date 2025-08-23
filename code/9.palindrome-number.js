/*
 * @lc app=leetcode id=9 lang=javascript
 *
 * [9] Palindrome Number
 */

// @lc code=start
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    /**
     * think: What data structure is used ？ stack !!! What are the stacks represented in javascript
     */
    const stack = [];
    if (x < 0) return false; // Negative numbers are not palindromes
    if (x === 0) return true; // 0 is a palindrome
    if (x % 10 === 0) return false; // Numbers ending with
    const str = x.toString();
    for (let i = 0; i < str.length; i++) {
        stack.push(str[i]);
    }
    for (let i = 0; i < str.length; i++) {
        if (str[i] !== stack.pop()) {
            return false; // If any character does not match, it's not a palindrome
        }
    }
    return true; // If all characters match, it is a palindrome
    
};
// @lc code=end

