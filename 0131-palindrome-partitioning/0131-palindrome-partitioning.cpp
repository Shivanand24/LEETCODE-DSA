class Solution {
public:
bool par( string s1){
    string s = s1;
    reverse(s.begin() , s.end());
    return s1 == s;
}

void par(string s , vector<vector<string>> &ans , int n ,vector<string> &temp) {
    if (n == 0){
        ans.push_back(temp);
        return;
    }



    for (int i = 0 ; i< n ; i++){
        string part= s.substr(0, i+1);
        if(par(part)){
                temp.push_back(part);
        

        par(s.substr(i+1) , ans , s.substr(i+1).size() , temp);

        temp.pop_back();
    }
    }
}
    vector<vector<string>> partition(string s) { 

        vector<vector<string>> ans ;

        int n = s.size();
        vector<string> temp;


        par(s , ans , n  , temp);
        return ans;


        
    }
};