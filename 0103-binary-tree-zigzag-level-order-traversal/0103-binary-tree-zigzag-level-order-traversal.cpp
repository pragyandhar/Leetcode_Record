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
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        bool flag = true;
        while (!Q.empty()) {
            int size = Q.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = Q.front();
                int index = flag ? i : size - i - 1;
                row[index] = node -> val;
                if (node -> left != NULL) Q.push(node -> left);
                if (node -> right != NULL) Q.push(node -> right);
                Q.pop();
            }
            flag = !flag;
            ans.push_back(row);
        }
        return ans;
    }
};