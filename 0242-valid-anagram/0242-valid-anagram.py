class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            exit()
            
        dictionary = {}

        for i in range(len(s)):
            if s[i] in dictionary:
                dictionary[s[i]] += 1
            else:
                dictionary[s[i]] = 1

        for i in range(len(t)):
            if t[i] not in dictionary:
                return False
                exit()
                
            dictionary[t[i]] -= 1

            if dictionary[t[i]] == 0:
                dictionary.pop(t[i])

        if len(dictionary) == 0:
            return True
        else:
            return False