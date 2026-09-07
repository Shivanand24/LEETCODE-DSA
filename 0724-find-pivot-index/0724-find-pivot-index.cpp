class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int sum = 0;
        int left = 0;
        int right = 0;

        // Calculate total sum
        for (int x : nums) {
            sum += x;
        }


        if (0 == sum - nums[0]) {
            return 0;
        }

        // Find pivot
        for (int i = 1; i < nums.size(); i++) {
                 left = left + nums[i-1];
            right = sum - left - nums[i];
           

            if (left == right) {
                return i;
            }

            
        }

        return -1;
    }
};