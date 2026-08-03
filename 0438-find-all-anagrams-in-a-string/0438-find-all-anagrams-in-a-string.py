class Solution:
    def allZero(self, freq: dict) -> bool:
        for i in freq.values():
            if i != 0:
                return False
        return True

    def findAnagrams(self, s: str, p: str) -> List[int]:
        result = list()

        # Count Frequency
        freq = {}
        for i in p:
            freq[i] = freq.get(i, 0) + 1
        
        # Sliding Window
        i, j = 0, 0
        k = len(p)
        while j < len(s):
            # Decrease the freq count if there is an element in the array
            if s[j] in freq:
                freq[s[j]] -= 1
            
            if j - i + 1 == k:
                if self.allZero(freq):
                    result.append(i)
                
                if s[i] in freq:
                    freq[s[i]] += 1
                
                i += 1
            
            j += 1

        return result