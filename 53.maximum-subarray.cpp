/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (48.25%)
 * Total Accepted:    1.5M
 * Total Submissions: 3.2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * A subarray is a contiguous part of an array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 104
 * -105 <= nums[i] <= 105
 * 
 * 
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() - 1;
        return maxSubArray(nums, 0, n);
    }

private:
    int maxSubArray(vector<int>& nums, const int& lo, const int& hi) {
        if (lo == hi)
            return nums[lo];

        int mid = lo + (hi - lo) / 2;
        // Divide.
        int leftMax = maxSubArray(nums, lo, mid);
        int rightMax = maxSubArray(nums, mid + 1, hi);
        int crossMax = crossSum(nums, lo, hi);
        // Combine.
        return max(crossMax, max(leftMax, rightMax));
    }

    int crossSum(vector<int>& nums, const int& lo, const int& hi) {
        int mid = lo + (hi - lo) / 2;
        
        // left side.
        int leftSum = 0, leftMax = INT_MIN;
        for (int i = mid; i >= lo; --i) {
            leftSum += nums[i];
            leftMax = max(leftSum, leftMax);
        }


        // right side.
        int rightSum = 0, rightMax = INT_MIN;
        for (int i = mid + 1; i <= hi; i++) {
            rightSum += nums[i];
            rightMax = max(rightSum, rightMax);
        }

        return leftMax + rightMax;

    }

};
