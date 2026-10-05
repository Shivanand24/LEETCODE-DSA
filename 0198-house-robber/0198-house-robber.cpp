class Solution {
public:

//  int fun(int idx , vector< int> &dp , vector<int> &nums){
//     if (idx == 0) return nums[idx];
//     if (idx < 0) return 0;
//    if (dp[idx] != -1) return dp[idx];

//    int pick = nums[idx] + fun(idx-2 , dp , nums);
//    int not_pick = 0 + fun(idx -1 , dp , nums);

//    return dp[idx] = max(pick , not_pick);
//  }
//     int rob(vector<int>& nums  ) {
//             int n = nums.size();
//         int idx = nums.size() -1;
//         vector<int> dp(n,-1);
//         return fun(idx , dp ,nums);


        
//     }


int rob(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2  =  0;
    for (int i = 1; i <n ; i++){
        int take = nums[i] ;
        if(i>1) take  = take+  prev2;
        int not_take = 0+prev;
        int curr = max(take , not_take);
        prev2 = prev;
        prev = curr;

    }
    return prev;
}
};