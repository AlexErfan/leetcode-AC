/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (31.47%)
 * Total Accepted:    712.3K
 * Total Submissions: 2.3M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -100.0 < x < 100.0
 * -231 <= n <= 231-1
 * -104 <= xn <= 104
 * 
 * 
 */
class Solution {
private:
    double fastPow(double x, int n) {
        if (n == 0)
            return 1.0;
        double half = fastPow(x, n/2);
        if (n % 2 ==0)
            return half*half;
        else
            return half*half*x;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            N = -N;
            x = 1/x;
        }
        return fastPow(x, N);

    }
};


