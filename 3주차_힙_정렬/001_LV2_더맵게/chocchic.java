import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for(int i = 0; i < scoville.length; i++){
            minHeap.offer(scoville[i]);
        }
               
        while(minHeap.peek() < K){
            if(minHeap.size() < 2) return -1;
            int peek1 = minHeap.poll();
            int peek2 = minHeap.poll();
            
            int new_peek = peek1 + (peek2*2);
            minHeap.offer(new_peek);
            answer++;
        }
        
        if(minHeap.peek() < K) return -1;
        
        return answer;
    }
}
