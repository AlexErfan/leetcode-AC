/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (72.11%)
 * Total Accepted:    1.2M
 * Total Submissions: 1.7M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters s.
 * 
 * 
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 105
 * s[i] is a printable ascii character.
 * 
 * 
 * 
 * Follow up: Do not allocate extra space for another array. You must do this
 * by modifying the input array in-place with O(1) extra memory.
 * 
 */
class Solution {
private:
    void helper(vector<char>& s, int left, int right) {
        if (left >= right)
            return;
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
        return helper(s, left, right);

    }
public:
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size() - 1);
    }
};
