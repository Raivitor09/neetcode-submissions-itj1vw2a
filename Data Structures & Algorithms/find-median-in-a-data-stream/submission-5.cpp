class MedianFinder {
private:
    priority_queue<double> max;
    priority_queue<double, vector<double>, greater<double>> min;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max.empty()) {
            max.push(num);
        } else {
            if (num >= max.top()) {
                min.push(num);
            } else {
                max.push(num);
            }
        }

        if (max.size() > min.size() + 1) {
            min.push(max.top());
            max.pop();
        } else if (min.size() > max.size()) {
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
        if ((max.size() + min.size()) % 2 == 0) {
            return (max.top() + min.top()) / 2.0;
        } else {
            if (max.size() > min.size()) {
                return max.top();
            } else {
                return min.top();
            }
        }
    }
};
