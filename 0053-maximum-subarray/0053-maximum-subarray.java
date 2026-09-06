class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length < 1) return 0;
        if (nums.length == 1) return nums[0];
        int maxSum = nums[0];
        int Sum = nums[0];
        for (int i = 1; i < nums.length; i ++){
            Sum = Math.max(Sum+=nums[i], nums[i]);
            maxSum = Math.max(Sum, maxSum);
        }
        return maxSum;
    }
}