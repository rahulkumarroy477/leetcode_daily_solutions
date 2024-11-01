class MedianFinder {
public:
    priority_queue<int> lh, rh;
    MedianFinder() {
    }
    
    void addNum(int num) {
        lh.push(-num);
        rh.push(-lh.top());
        lh.pop();

        if(rh.size() > lh.size()){
            lh.push(-rh.top());
            rh.pop();
        }
        
    }
    
    double findMedian() {
        
        if(lh.size() == rh.size())  return (rh.top() - lh.top())/2.0;
        return -lh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */