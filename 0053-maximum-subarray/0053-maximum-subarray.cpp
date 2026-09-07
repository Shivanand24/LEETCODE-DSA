class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int curr_sum =  0;
        int max_number = INT_MIN;

        for (int i = 0 ; i< nums.size() ; i++ ) {

       
        curr_sum =  max(nums[i] , nums[i] + curr_sum);
        max_number = max(max_number , curr_sum);
        }
         return max_number;
        
    }
   
};