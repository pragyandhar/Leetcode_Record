# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = collections.deque()
        visited = list()
        if not root:
            return visited
        
        q.append(root)

        while q:
            same_level = list()
            for i in range(len(q)):
                current = q.popleft()
                same_level.append(current.val)
                if current.left:
                    q.append(current.left)
                if current.right:
                    q.append(current.right)
            visited.append(same_level)
        return visited

        