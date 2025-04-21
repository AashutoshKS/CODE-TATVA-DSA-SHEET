//PROBLEM :

        The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, 
        and the median is the mean of the two middle values.
        
        For example, for arr = [2,3,4], the median is 3.
        For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
        Implement the MedianFinder class:
        
        MedianFinder() initializes the MedianFinder object.
        void addNum(int num) adds the integer num from the data stream to the data structure.
        double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.


//APPROACH :
        Use Min heap and Max Heap to maintain the sorted order of the list, ie maintain size of both the list in each step
              ie. -> For even number of elements both heaps must have n/2 elements and avg of both top elements is the median
                  -> for odd len min heap will have n/2 + 1 element and the top one will be the median

//COMPLEXITY :
        TIME COMPLEXITY : O(N.logn)
        SPACE COMPLEXITY : O(n)


//CODE :
        class MedianFinder {
        public:
            priority_queue<int> maxHeap;
            priority_queue<int, vector<int>, greater<>> minHeap;
            void addNum(int num) {
                if (maxHeap.empty() || num <= maxHeap.top()) {
                    maxHeap.push(num);
                }
                else {
                    minHeap.push(num);
                }
                
                if (maxHeap.size() < minHeap.size()) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
                else if (maxHeap.size() - minHeap.size() > 1) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }
            double findMedian() {
                if (maxHeap.size() == minHeap.size())
                    return (maxHeap.top() + minHeap.top()) / 2.0;
                return maxHeap.top();
            }
        };
        
        
        
        
