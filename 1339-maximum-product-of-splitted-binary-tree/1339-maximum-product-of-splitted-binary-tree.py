# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        # DFS to calculate the sum of all the nodes of the entire tree
        def sum_of_tree(node: Optional[TreeNode]) -> int:
            if node is None:
                return 0
            return node.val + sum_of_tree(node.left) + sum_of_tree(node.right)

        # Iterate and find the maximum product
        def find_max_product(node: Optional[TreeNode]) -> int:
            if node is None:
                return 0
            subtree_sum = node.val + find_max_product(node.left) + find_max_product(node.right)
            nonlocal ans, total_tree_sum
            if total_tree_sum > subtree_sum:
                ans = max(ans, subtree_sum*(total_tree_sum - subtree_sum))
            return subtree_sum

        # Define Constraint
        MOD = 10**9+7
        total_tree_sum = sum_of_tree(root)
        ans = 0
        find_max_product(root)
        return ans % MOD
                
        