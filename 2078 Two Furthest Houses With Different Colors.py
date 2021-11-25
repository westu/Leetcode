class Solution(object):
    def maxDistance(self, colors):
        """
        :type colors: List[int]
        :rtype: int
        """
        max_dist = 0
        first_two_colors = []
        for i in xrange(len(colors)):
            if len(first_two_colors) == 0:
                first_two_colors.append((colors[i], i))
                continue
            if colors[i] != first_two_colors[0][0]:
                max_dist = max(max_dist, i - first_two_colors[0][1])
            elif len(first_two_colors) == 2 and colors[i] != first_two_colors[1][0]:
                max_dist = max(max_dist, i - first_two_colors[1][1])
            if len(first_two_colors) == 1 and colors[i] != first_two_colors[0][0]:  # add the other color's info
                first_two_colors.append((colors[i], i))
        return max_dist
        
