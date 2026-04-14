class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        if(m != 0) {
            while(m < nums1.size()) {
                if(nums1[i] > nums2[j]) {
                    nums1[m] = nums2[j];
                    m++, i++, j++;
                } else {
                    i++;
                }
            }
            sort(nums1.begin(), nums1.end());
        } else {
            while(j < nums2.size()) {
                nums1[i] = nums2[j];
                i++, j++;
            }
        }
    }
};