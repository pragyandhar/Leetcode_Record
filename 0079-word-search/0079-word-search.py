class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ROWS, COLS = len(board), len(board[0]) # End points
        path = set() # The letter already visited

        def dfs(r, c, i):
            # If the word is complete
            if i == len(word):
                return True
            # Out of bounds condition or we are pointing at a letter which is not available in the word or we are pointing at a letter which is already visited
            if (r < 0 or c < 0 or r >= ROWS or c >= COLS or word[i] != board[r][c] or (r,c) in path):
                return False
            
            path.add((r,c))
            res = (dfs(r+1, c, i+1) or dfs(r-1, c, i+1) or dfs(r, c+1, i+1) or dfs(r, c-1, i+1))
            path.remove((r,c))
            return res
        
        for r in range(ROWS):
            for c in range(COLS):
                if dfs(r, c, 0):
                    return True
        
        return False
            