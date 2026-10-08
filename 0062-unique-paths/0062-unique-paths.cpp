class Solution {
public:
int fun(int &m , int &n , int i , int j ,vector<vector<int>> &dp ){

    if (i == n-1 || j == m-1){
        return 1; //base case
    }

    if (i<0 || i >= n || j<0 || j >= m ){
        return 0;  // edge case
    }


    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = fun(m,n,i+1,j,dp) + fun(m,n,i,j+1,dp);



}

    int uniquePaths(int m, int n) {

        int i = 0 ;
        int j = 0 ;
        vector<vector<int>> dp(n);
            for(int i = 0 ; i < n ; i++){
                vector<int>t(m , -1);
                dp[i]  = t;
            }
           
           
            


            return fun(m,n,i,j,dp);
        






        
    }
};