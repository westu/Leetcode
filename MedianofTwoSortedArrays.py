class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        len1 = len(nums1)
        len2 = len(nums2)
        if (len1 + len2) % 2 == 1:
            return self.findKthInSortedArrays(nums1, nums2, (len1 + len2) / 2 + 1)
        else:
            return (self.findKthInSortedArrays(nums1, nums2, (len1 + len2) / 2) \
                + self.findKthInSortedArrays(nums1, nums2, (len1 + len2) / 2 + 1)) / 2.0

    def findKthInSortedArrays(self, nums1, nums2, k):
        if len(nums1) == 0:
            return nums2[k - 1]
        if len(nums2) == 0:
            return nums1[k - 1]

        if k == 1:
            return min(nums1[0], nums2[0])

        if len(nums1) < k / 2:
            return self.findKthInSortedArrays(nums1, nums2[k / 2 : ], k - k / 2)
        if len(nums2) < k / 2:
            return self.findKthInSortedArrays(nums1[k / 2 : ], nums2, k - k / 2)

        if nums2[k / 2 - 1] < nums1[k / 2 - 1]:
            return self.findKthInSortedArrays(nums1, nums2[k / 2 : ], k - k / 2)
        else:
            return self.findKthInSortedArrays(nums1[k / 2 : ], nums2, k - k / 2)
