class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    long long maxSum = INT_MIN, currSum = 0;
    for (ll i = 0; i < n; i++) {
        currSum += nums[i];
        
        if (maxSum < currSum) {
            maxSum = currSum;
        }
        
        if (currSum < 0) {
            currSum = 0;
        }
    }
    
    return maxSum;
    return 0;
    }
};
