class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxno =  nums[0];
        int minno =nums[0];

         int res = nums[0];

         for (int i =  1  ; i < nums.size() ; i++){
            int v1 = nums[i];
            int v2 =   nums[i] * maxno;
            int v3 = nums[i] * minno;

            maxno = max(v1 , max(v2 , v3));
            minno = min (v1 , min(v2, v3));
            res = max(res , max(maxno , minno));


            
                     }

                     return res;
        
         
        
    }
};