/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (56.35%)
 * Total Accepted:    409.3K
 * Total Submissions: 726.4K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of structurally unique BST's (binary
 * search trees) which has exactly n nodes of unique values from 1 to n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 19
 * 
 * 
 */
class Solution {
public:
    int numTrees(int n) {
        vector<long> G(n, 0);
        G[0] = 1;
        
        for (int i = 1; i < n; i++) {
            G[i] = G[i-1] * (4*i+2) / (i+2);
        }
        
        return G[n-1];

    }
};
