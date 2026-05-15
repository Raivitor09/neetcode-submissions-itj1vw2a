class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> pairs;

        for(int i = 0; i < points.size(); i++) {
            int euclidean_distance = sqrt(pow(points[i][0] - 0, 2) + pow(points[i][1] - 0, 2));
            pairs.push_back({euclidean_distance, points[i]});
        }

        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minHeap;
        for(int i = 0; i < pairs.size(); i++) {
            minHeap.push(pairs[i]);
        }

        vector<vector<int>> res;
        while(k > 0) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }

        return res;
    }
};
