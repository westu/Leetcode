class Solution(object):
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        ans = ''
        vowel_dict = {'a' : 1, 'e' : 1, 'i' : 1, 'o' : 1, 'u' : 1}
        word_list = S.split(' ')
        for i in xrange(0, len(word_list)):
            word = word_list[i]
            if word_list[i][0].lower() in vowel_dict:
                word += 'ma'
            else:
                word = word[1 : len(word)] + word[0] + 'ma'
            for j in xrange(1, i + 2):
                word += 'a'
            ans += word + ' '
        return ans.strip()
