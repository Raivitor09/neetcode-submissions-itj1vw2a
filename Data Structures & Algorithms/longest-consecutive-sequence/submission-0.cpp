class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mySet;

        for (int i = 0; i < nums.size(); i++) {
            mySet.insert(nums[i]);
        }

        int maxLen = 0;

        for (int num : mySet) {
            if (mySet.find(num - 1) != mySet.end()) continue;

            int currLen = 1;

            while (mySet.find(num + currLen) != mySet.end()) currLen++;

            maxLen = max(currLen, maxLen);
        }

        return maxLen;
    }
};
