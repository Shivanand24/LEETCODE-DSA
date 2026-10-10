class Solution {
public:

int fun( vector<int>& arr , int i , int k , vector<vector<int>> &dp , int n){
   

    if ( i== n) return 0;
    if (k ==0) return 0;

    if (dp[i][k] != -1) return dp[i][k];

    if ( k==2){
        int c1 = fun(arr , i+1, k-1, dp , n) - arr[i];
        int c2 = fun(arr,i+1 , k, dp , n);

        return dp[i][k] = max(c1 , c2);
    } else{
        int c1 = fun(arr , i+1, k-1, dp , n) + arr[i];
        int c2 = fun(arr,i+1 , k, dp , n);
         return dp[i][k] = max(c1 , c2);

    }
}
    int maxProfit(vector<int>& arr) {

        int i = 0 ;
        int  n = arr.size();
         int k = 2;


        vector<vector<int>> dp(n+1);
        for ( int i = 0 ; i<= n ; i++){
            vector<int> t (k+1 , -1);

            dp[i] = t;
        }

       return  fun(arr, i, k , dp, n);


    }
};