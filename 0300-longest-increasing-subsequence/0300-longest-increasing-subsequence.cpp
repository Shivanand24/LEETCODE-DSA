class Solution {
public:

// int fun( vector<int>& nums , int i,  int prev , vector<vector< int>> &dp, int n ){

// if ( i  == n ) return 0;
// //changing are 2 value onlt i.e i ,prev
// if ( dp[i][prev+1] != - 1 ) return dp[i][prev+1];


// if (prev == -1 || nums[i] > nums[prev]){
//     int c1= 1+  fun(nums , i+1 , i , dp,n);//include
//         int c2 = fun(nums , i+1 , prev ,dp,n); // without including forming longest subsequence

//         return dp[i][prev+1] =  max(c1,c2);
// }

// return dp[i][prev+1] = fun(nums , i+1 , prev , dp, n);

// }


//     int lengthOfLIS(vector<int>& nums) {


// int n  = nums.size();
// vector<vector<int>> dp(n);
// for (int i = 0; i<n ; i++) {
//     vector<int> t(n+1, -1);
//     dp[i] = t;

// }

//  int prev = -1;


//     int i = 0;

//     return fun( nums, i, prev , dp , n);

        
//     }
// };

 int lengthOfLIS(vector<int>& nums) {
    int  n = nums.size();
    vector<int> res(n);
    int i, j;
    for (i = 0 ; i< n ; i++){

        res[i] = 1;
        for (int j =0 ; j< i ; j++){
            if (nums[i] > nums [j]){
                res[i] = max(res[i] , res[j] +1);
            }

        }
    }
            int ans= 1;
            for (int i = 0 ; i<= res.size() -1 ; i++){
                ans = max(ans , res[i]);

            }
            return ans;



        
 } 
 };

