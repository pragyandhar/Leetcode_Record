class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        w1p = 0
        w2p = 0

        output = ""

        while (w1p < len(word1) or w2p < len(word2)):
            if (w1p < len(word1)) :    
                output += word1[w1p]
                w1p += 1
            if (w2p < len(word2)) :
                output += word2[w2p]
                w2p += 1
        
        return output
