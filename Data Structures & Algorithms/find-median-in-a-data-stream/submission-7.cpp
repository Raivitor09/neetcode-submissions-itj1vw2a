class MedianFinder {
public:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;
    MedianFinder() {
        
    }

    void balance() {
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() > num) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        balance();
    }
    
    double findMedian() {
        if(maxHeap.size() != minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */