class MedianFinder {
    private PriorityQueue<Integer> minHeap;
    private PriorityQueue<Integer> maxHeap;
    int size;
    public MedianFinder() {
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        size = 0;
    }
    
    public void addNum(int num) {
        size++;
        if (maxHeap.size() == 0 || num <= maxHeap.peek()) {
            maxHeap.add(num);
        } else {
            minHeap.add(num);
        }
        
        if (minHeap.size() - maxHeap.size() == 2) {
            maxHeap.add(minHeap.remove());
        }
        if (maxHeap.size() - minHeap.size() == 2) {
            minHeap.add(maxHeap.remove());
        }
    }
    
    public double findMedian() {
        if (minHeap.size() != maxHeap.size()) {
            return minHeap.size() > maxHeap.size() ? minHeap.peek() : maxHeap.peek();
        } else {
            return (minHeap.peek() + maxHeap.peek()) / 2.0;
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */