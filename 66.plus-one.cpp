/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.03%)
 * Total Accepted:    905.2K
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of decimal digits representing a non-negative
 * integer, increment one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contains a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = [0]
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * 
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        return helper(digits, digits.size()-1);
    }

private:
    vector<int> helper(vector<int>& digits, const int& idx) {
       if (digits[idx] < 9) {
           ++digits[idx];
           return digits;
       } else { // digits = 9.
            if (idx != 0) { // Not the leftmots digit.
                digits[idx] = 0;
                return helper(digits, idx - 1);
            } else { // reached the leftmost digit.
               digits[0] = 1;
               digits.push_back(0);
               return digits;
            }
       }
    }
};
