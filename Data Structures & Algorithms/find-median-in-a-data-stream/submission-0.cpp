class MedianFinder {
private:
    vector<double> v;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        v.push_back(num);
        sort(v.begin(), v.end());
    }
    
    double findMedian() {
        int l = 0, r = v.size() - 1;
        int mid = (long long) l + r / 2;
        double median;
        if (v.size() % 2 == 0) {
            median = (v[mid] + v[mid + 1]) / 2;
            return median;
        } else {
            return v[mid];
        }
    }
};
