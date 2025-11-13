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
    int height_balanced(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int lh = height_balanced(root -> left);
        int rh = height_balanced(root -> right);
        
        // These two lines make the difference
        if (lh == -1 || rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;        
    }
    
    bool isBalanced(TreeNode* root) {
        return height_balanced(root) != -1;
    }
};