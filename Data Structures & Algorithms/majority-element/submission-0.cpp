class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int i = 0, count = 0;
        sort(nums.begin(), nums.end());

        while(i < n) {
            int curr = nums[i];
            count = 0;
            while(i < n && curr == nums[i]) {
                i++, count++;
            }
            if(count > n/2) return curr;
        }

        return 0;
    }
};