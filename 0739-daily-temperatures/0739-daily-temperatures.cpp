class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        
        stack <int> s;
    int n = a.size();
    vector <int> res(n , 0);
        s.push(n-1);
        res[n-1] = 0;
        for (int i = n-2 ; i >= 0 ;i--) {
            while(!s.empty() && a[s.top()] <= a[i]) {
                s.pop();
            }

            if (s.empty()){
                res[i] = 0;
            } else {
                res[i] = s.top() - i ;
                
            }
            s.push(i);

         
        }

           return res;


        
    }
};