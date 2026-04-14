class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];

            // Se for negativo, troca max com min
            if (num < 0) {
                swap(currMax, currMin);
            }

            currMax = max(num, currMax * num);
            currMin = min(num, currMin * num);

            answer = max(answer, currMax);
        }

        return answer;
    }
};