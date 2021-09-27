/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (49.51%)
 * Total Accepted:    1.1M
 * Total Submissions: 2.3M
 * Testcase Example:  '2'
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 45
 * 
 * 
 */
class Solution {
private:
    int helper(int step, int n, vector<int>& cache) {
        if (step == n)
            return 1;
        else if (step > n)
            return 0;
        else if (cache[step] > 0)
            return cache[step];
        // recursive relation
        cache[step] = helper(step+1, n, cache) + helper(step+2, n, cache);
        return cache[step];
    }
public:
    int climbStairs(int n) {
        vector<int> cache (n+1, 0);
        return helper(0, n, cache);

    }
};
