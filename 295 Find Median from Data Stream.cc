class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        heap.insert(num);
        int n = static_cast<int>(heap.size());
        if (n == 1) {
            heap_it = heap.begin();
        } else {
            if (n % 2 == 0 && num < *heap_it) {
                --heap_it;
            } else if (n % 2 == 1 && num >= *heap_it) {
                ++heap_it;
            } 
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int n = static_cast<int>(heap.size());
        if (n % 2 == 1) {
            return *heap_it;
        } else {
            std::multiset<int>::iterator next_it = heap_it;
            ++next_it;
            return (*heap_it + *next_it) / 2.0;
        }
    }

private:
    std::multiset<int> heap;
    std::multiset<int>::iterator heap_it;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
