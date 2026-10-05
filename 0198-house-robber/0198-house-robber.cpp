class Solution {
public:

 int fun(int idx , vector< int> &dp , vector<int> &nums){
    if (idx == 0) return nums[idx];
    if (idx < 0) return 0;
   if (dp[idx] != -1) return dp[idx];

   int pick = nums[idx] + fun(idx-2 , dp , nums);
   int not_pick = 0 + fun(idx -1 , dp , nums);

   return dp[idx] = max(pick , not_pick);
 }
    int rob(vector<int>& nums  ) {
            int n = nums.size();
        int idx = nums.size() -1;
        vector<int> dp(n,-1);
        return fun(idx , dp ,nums);


        
    }
};