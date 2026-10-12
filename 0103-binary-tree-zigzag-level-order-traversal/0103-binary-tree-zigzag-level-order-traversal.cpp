/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {



        vector<vector<int>> res;

        if (root == NULL) return res;

        int leftright = 1;
        
    queue<TreeNode*>q;
    q.push(root);

    while (!q.empty()){
        int line = q.size();
        vector<int> temp(line) ;
         int first = 0;
            int last = line - 1;

        while (line -- ){

            
            TreeNode*t = q.front();
            q.pop();

           if (leftright == 1){
            temp[first] = t -> val;
            first++;
           } else{
            temp[last] = t -> val;
            last--;
           }
            if (t->left != NULL){
                q.push(t -> left);
            }

            if (t -> right != NULL){
                q.push(t -> right);
            }


        }

        res.push_back(temp);
         leftright = 1 - leftright;
    }

    return res;

        
    }
};