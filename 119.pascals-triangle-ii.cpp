/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (54.43%)
 * Total Accepted:    418.1K
 * Total Submissions: 767.8K
 * Testcase Example:  '3'
 *
 * Given an integer rowIndex, return the rowIndexth (0-indexed) row of the
 * Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 * 
 * 
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= rowIndex <= 33
 * 
 * 
 * 
 * Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
 * space?
 * 
 */
class Solution {
private:
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        else if (rowIndex == 1)
            return {1,1};
        
        vector<int> row;
        vector<int> prev = getRow(rowIndex-1);
        
        row.push_back(1);
        for (int i = 0; i < prev.size()-1; i++) {
            row.push_back(prev[i] + prev[i+1]);
        }
        row.push_back(1);
        return row;

    }
};
