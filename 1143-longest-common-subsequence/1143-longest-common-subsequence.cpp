class Solution {
public:

int fun( string &s1 , string &s2 , int  n , int m , int i , int j ,vector<vector<int>> &dp){
    if (i == n || j == m) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i]  == s2[j]) return dp[i][j] = 1+ fun(s1 , s2, n ,m,i+1,j+1, dp);

    int c1 = fun(s1 , s2 , n , m , i+1 , j , dp  );
     int c2 = fun(s1 , s2 , n , m , i , j+1 , dp  );
     return dp[i][j] = max(c1,c2);
}
    int longestCommonSubsequence(string s1, string s2) {

        int  n = s1.size();
        int m = s2.size();

        int i =0 ;
        int j =0;

        vector<vector<int>>dp(n);
        for (int i =0 ; i< n ;i++){
            vector<int> t (m , -1);
            dp[i] = t;
        }


        
        return fun(s1, s2, n,m,i,j,dp);


        
    }
};