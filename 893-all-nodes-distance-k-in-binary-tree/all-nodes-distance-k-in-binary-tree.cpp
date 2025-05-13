/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void fun(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        fun(root,parent);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        q.push(target);
        vis[target]=true;
        int dist =0;
        while(!q.empty()){
            int size = q.size();
            if(dist==k)break;
            dist++;
            for(int i =0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    vis[curr]=true;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]){
                    vis[curr]=true;
                    q.push(curr->right);
                }
                if(parent[curr]&&!vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
                }
            }


        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);


        }


    return res;}
};