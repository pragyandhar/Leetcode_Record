class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        count = 0
        maxV = 0

        i = j = 0

        isVowel = lambda ch: ch in 'aeiou'

        while j < len(s):
            if isVowel(s[j]):
                count += 1
            
            if j - i + 1 == k:
                maxV = max(maxV, count)
                if isVowel(s[i]):
                    count-= 1
                i += 1
            
            j += 1
        
        return maxV