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
        recurse(nums, 0);
        return maxOverAll;
    }

private:
    int maxOverAll = INT_MIN;

protected:
    int recurse(vector<int>& nums, const int &index) {
        int maxSoFar = 0;
        if (index == nums.size()-1)
            maxSoFar = nums[index];
        else
            maxSoFar = max(nums[index], nums[index] + recurse(nums, index + 1));
        maxOverAll = max(maxOverAll, maxSoFar);
        return maxSoFar;
    }
};
