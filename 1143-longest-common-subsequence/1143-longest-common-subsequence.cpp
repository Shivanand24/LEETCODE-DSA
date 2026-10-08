class Solution {
public:

// int fun( string &s1 , string &s2 , int  n , int m , int i , int j ,vector<vector<int>> &dp){
//     if (i == n || j == m) return 0;

//     if (dp[i][j] != -1) return dp[i][j];

//     if (s1[i]  == s2[j]) return dp[i][j] = 1+ fun(s1 , s2, n ,m,i+1,j+1, dp);

//     int c1 = fun(s1 , s2 , n , m , i+1 , j , dp  );
//      int c2 = fun(s1 , s2 , n , m , i , j+1 , dp  );
//      return dp[i][j] = max(c1,c2);
// }
    int longestCommonSubsequence(string s1, string s2) {

        int  n = s1.size();
        int m = s2.size();

        

        vector<vector<int>>dp(n+1);
        for (int i =0 ; i< n+1 ;i++){
            vector<int> t (m+1 , 0);
            dp[i] = t;
        }
        for (int i = 0; i < n; i++) {
        dp[i][m] = 0;
    }

    for (int j = 0; j < m; j++) {
        dp[n][j] = 0;
    }

        for (int i = n-1 ;  i >= 0 ; i--){
            for (int j = m-1 ; j >= 0 ; j--){

                if(s1[i] == s2[j]){
                dp[i][j] = 1+dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j] ,dp[i][j+1]);
                }
            } 
        }

            return dp[0][0];
        }



        
       // return fun(s1, s2, n,m,i,j,dp);


        
    


    
};