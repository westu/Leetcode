class Solution(object):
    def timeRequiredToBuy(self, tickets, k):
        """
        :type tickets: List[int]
        :type k: int
        :rtype: int
        """
        totalTime = 0
        for i in xrange(len(tickets)):
            if i <= k:
                totalTime += min(tickets[i], tickets[k])
            else:
                totalTime += min(tickets[i], tickets[k] - 1)
        return totalTime
        
