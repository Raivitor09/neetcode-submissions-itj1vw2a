class MedianFinder {
public:
    priority_queue<double> max;
    priority_queue<double, vector<double>, greater<double>> min;
    MedianFinder() {
        
    }
    void balance() {
        if(max.size() > min.size() + 1) {
            min.push(max.top());
            max.pop();
        } else if(min.size() > max.size()){
            max.push(min.top());
            min.pop();
        }
    }
    void addNum(int num) {
        if(max.empty() || max.top() > num) {
            max.push(num);
        } else {
            min.push(num);
        }
        balance();
    }
    
    double findMedian() {
        if(max.size() != min.size()) {
            return max.top();
        } else {
            return (max.top() + min.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */