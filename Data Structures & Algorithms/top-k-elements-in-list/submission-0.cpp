class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> index;

        for (int i = 0; i < nums.size(); i++) {
            index[nums[i]]++;
        }

        auto comp = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        };

        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(comp)> maxHeap(comp);

        for(auto& it : index) {
            maxHeap.push({it.first, it.second});
        }

        vector<int> output;
        while(k > 0 && !maxHeap.empty()) {
            pair<int, int> firstTop = maxHeap.top();
            maxHeap.pop();

            output.push_back(firstTop.first);
            k--;
        }

        return output;

    }
};
