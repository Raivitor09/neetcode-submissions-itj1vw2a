class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int minK = r; // by default

        while(l <= r) {
            int k = ((int) l + r) / 2;

            long long totalTime = 0;
            for(int p: piles) {
                if(p % k == 0) {
                    totalTime += p / k;
                } else {
                    totalTime += (p / k) + 1;
                }
            }

            if(totalTime <= h) {
                minK = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }

        return minK;
    }
};
