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
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        bool flag = true;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(flag){
                    level.push_back(node->val);
                }else{
                    level.insert(level.begin(),node->val);
                }
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }
            ans.push_back(level);
            flag= !flag;
        }
        
    return ans;}
};