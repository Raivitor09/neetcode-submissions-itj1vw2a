class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;

        int currSum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            int diff = currSum - k;
            count += prefixSum[diff];
            prefixSum[currSum]++;
        }

        return count;
    }
};