# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        q = collections.deque()
        answer = list()
        if not root:
            return answer
        q.append(root)

        while q:
            size = len(q)
            averageLvl = 0
            for i in range(size):
                curr = q.popleft()
                averageLvl += curr.val
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            averageLvl /= size
            answer.append(averageLvl)
        
        return answer
