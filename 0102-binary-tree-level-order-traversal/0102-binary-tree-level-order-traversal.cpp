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
    void LevelOrder(TreeNode* node, vector<vector<int>>& ans) {
        if (node == NULL) return;
        queue<TreeNode*> Q;
        Q.push(node);
        while (!Q.empty()) {
            int size = Q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* current = Q.front();
                level.push_back(current -> val);
                if (current -> left != NULL) Q.push(current->left);
                if (current -> right != NULL) Q.push(current->right);
                Q.pop();
            }
            ans.push_back(level);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        LevelOrder(root, ans);
        return ans;
    }
};