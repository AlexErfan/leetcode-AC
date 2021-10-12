/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 *
 * https://leetcode.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (62.25%)
 * Total Accepted:    99.2K
 * Total Submissions: 158.4K
 * Testcase Example:  '"00110011"'
 *
 * Give a binary string s, return the number of non-empty substrings that have
 * the same number of 0's and 1's, and all the 0's and all the 1's in these
 * substrings are grouped consecutively.
 * 
 * Substrings that occur multiple times are counted the number of times they
 * occur.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of consecutive
 * 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 * Notice that some of these substrings repeat and are counted the number of
 * times they occur.
 * Also, "00110011" is not a valid substring because all the 0's (and 1's) are
 * not grouped together.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "10101"
 * Output: 4
 * Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
 * number of consecutive 1's and 0's.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 105
 * s[i] is either '0' or '1'.
 * 
 * 
 */
class Solution {
public:
    int countBinarySubstrings(string s) {
        // four ints with size 0.
        vector<int> groups (s.size(), 0);

        // first element as a gorup.
        groups[0] = 1;
        int t = 0;

        for (int i = 1; i < groups.size(); i++) {
            if (s[i-1] != s[i]) {
                groups[++t] = 1;
            } else {
                groups[t]++;
            }
        }

        // count the result.
        int result = 0;
        for (int i = 1; i <= t; i++) {
            result += min(groups[i-1], groups[i]);
        }
        
        return result;
    }
};
