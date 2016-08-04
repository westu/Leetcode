class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        strs = str.split(' ')
        if len(pattern) != len(strs):
            return False
        for i in xrange(len(pattern)):
            for j in xrange(len(pattern)):
                if pattern[i] == pattern[j] and strs[i] != strs[j]:
                    return False
                if pattern[i] != pattern[j] and strs[i] == strs[j]:
                    return False
        return True
