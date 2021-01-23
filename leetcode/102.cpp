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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> Q;
        Q.push(root);
        
        while (!Q.empty()){
            TreeNode *curNode;
            int size = Q.size();
            vector<int> v;
            for (int i = 0; i < size; i++){
                curNode = Q.front();
                Q.pop();
                
                v.push_back(curNode->val);
                if (curNode->left)
                    Q.push(curNode->left);
                if (curNode->right)
                    Q.push(curNode->right);
            }
            ans.push_back(v);            
        }
        
        return ans;
    }
};