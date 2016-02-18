class Solution {
public:
    /**
     * @param nums1: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param nums2: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int nums1[], int m, int nums2[], int n) {
        int p1(m - 1), p2(n - 1);
        for (int i = m + n - 1; i >= 0; --i) {
            if (p2 == -1 || p1 >= 0 && nums1[p1] >= nums2[p2]) {
                nums1[i] = nums1[p1];
                --p1;
            } else {
                nums1[i] = nums2[p2];
                --p2;
            }
        }
    }
};
