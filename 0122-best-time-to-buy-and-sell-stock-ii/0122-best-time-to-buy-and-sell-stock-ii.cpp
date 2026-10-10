class Solution {
public:

// int fun( vector<int>& arr , int i , int k , vector<vector<int>> &dp , int n){
   

//     if ( i== n) return 0;
//     if (k ==0) return 0;

//     if (dp[i][k] != -1) return dp[i][k];

//     if ( k==2){
//         int c1 = fun(arr , i+1, k-1, dp , n) - arr[i];
//         int c2 = fun(arr,i+1 , k, dp , n);

//         return dp[i][k] = max(c1 , c2);
//     } else{
//         int c1 = fun(arr , i+1, 2 , dp , n) + arr[i];
//         int c2 = fun(arr,i+1 , k, dp , n);
//          return dp[i][k] = max(c1 , c2);

//     }
// }
    int maxProfit(vector<int>& arr) {

        int i = 0 ;
        int  n = arr.size();
         int k = 2;


        vector<vector<int>> dp(n+1);
        for ( int i = 0 ; i<= n ; i++){
            vector<int> t (k+1 , -1);

            dp[i] = t;
        }
        for (int i =  0; i<= n; i++){
            dp[i][0] = 0;
        }

        for (int j = 0 ; j <= k; j++){
            dp[n][j] =0;
        }


       //return  fun(arr, i, k , dp, n);

      for(int i =n-1 ; i >= 0 ; i--){
        for (int j  = 1 ; j <= k ; j++){
            if ( j == 2){
                dp[i][j] = max(dp[i+1][j-1]  - arr[i] , dp[i+1][j]);
            }else{
                dp[i][j] = max(dp[i+1][2]  + arr[i] , dp[i+1][j]);
            }
        }
      }
        return dp[0][2];

    }
};