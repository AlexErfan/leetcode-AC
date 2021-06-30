class Solution {
    public int[] twoSum(int[] nums, int target) {
        int a = 1;
        int b = -1;
        
        while (a <= nums.length) {
            for (int i = a; i < nums.length; i++) {
						// try combinations with different space intervals.
                if (nums[i] + nums[i-a] == target) {
                    b = i;
										// keep the value of i when for loop exits.
                    break;
                }
            }
            
            if (b != -1) {
                break;
								// prevent variable a from increasing.
            }
            a++;
        }
        
        return new int[]{b-a, b};
    }
}
