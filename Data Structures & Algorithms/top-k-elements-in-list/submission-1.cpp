class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int n: nums) {
            freq[n]++;
        }
        vector<pair<int, int>> pairs;
        for(auto i : freq) {
            pairs.push_back({i.first, i.second});
        }

        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });

        vector<int> res;
        for(auto i: pairs) {
            if(k == 0) break;
            res.push_back(i.first);
            k--;
        }

        return res;
    }
};
