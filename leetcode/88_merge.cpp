class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int point = m + n - 1;
        --m;
        --n;
        while ((n >= 0) && (m >= 0)) {
            (nums1[m] > nums2[n]) ? (nums1[point--] = nums1[m--]): (nums1[point--] = nums2[n--]);
        }

        while (n >= 0) {
            nums1[point--] = nums2[n--];
        }
    }
};
