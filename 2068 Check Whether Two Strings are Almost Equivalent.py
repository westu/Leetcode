class Solution(object):
    def letterCounter (self, word, freDict):
        for letter in word:
            if letter not in freDict:
                freDict[letter] = 1
            else:
                freDict[letter] = freDict[letter] + 1
                
    def checkFre(self, freDict1, freDict2):
        for key in freDict1:
            numInDict2 = 0
            if key in freDict2:
                numInDict2 = freDict2[key]
            if abs(freDict1[key] - numInDict2) > 3:
                return False
        return True
    
    def checkAlmostEquivalent(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: bool
        """
        freDict1 = {}
        freDict2 = {}
        self.letterCounter(word1, freDict1)
        self.letterCounter(word2, freDict2)
        
        return self.checkFre(freDict1, freDict2) and self.checkFre(freDict2, freDict1)
