import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
    
        Arrays.sort(times);
               
        long left = 1; 
        long right = (long)times[times.length-1]*(long)n;
        long answer = right;
        long mid = 0;

        while(left <= right){
            mid = (left+right)/2;

            long nn = 0;
            for(int i = 0 ; i < times.length; i++){
                nn += (long)mid/(long)times[i];
            }
            
            
            if(nn < n) left = mid + 1;
            else{
                right = mid - 1;
                answer = answer > mid ? mid : answer;
                
            }
        
        }

        return answer;
    }
}
