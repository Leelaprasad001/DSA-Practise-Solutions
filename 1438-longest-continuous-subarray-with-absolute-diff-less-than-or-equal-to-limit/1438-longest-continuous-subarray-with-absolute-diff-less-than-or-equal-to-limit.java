class Solution {
    public int longestSubarray(int[] nums, int limit) {
        int n = nums.length;
        int start = 0, end = 0;
        int maxSubArrayLen = 0;        
        Deque<Integer> minDeque = new LinkedList<>();
        Deque<Integer> maxDeque = new LinkedList<>();
        for(end = 0; end<n; end++) {
            while(!minDeque.isEmpty() && nums[minDeque.peekLast()] > nums[end]) {
                minDeque.pollLast();
            }
            
            while(!maxDeque.isEmpty() && nums[maxDeque.peekLast()] < nums[end]) {
                maxDeque.pollLast();
            }
            
            minDeque.addLast(end);
            maxDeque.addLast(end);
                        
            while(start < end && nums[maxDeque.peekFirst()] - nums[minDeque.peekFirst()] > limit) {
                start++;
                while(!maxDeque.isEmpty() && maxDeque.peekFirst() < start) {
                    maxDeque.pollFirst();
                }
                
                while(!minDeque.isEmpty() && minDeque.peekFirst() < start) {
                    minDeque.pollFirst();
                }           
            }

            maxSubArrayLen = Math.max(maxSubArrayLen, end-start+1);
        }
     
        return maxSubArrayLen;
    }
}