import java.util.*;
class Solution {
    public int solution(int distance, int[] rocks, int n) {
        int answer = 0;
        
        Arrays.sort(rocks);
                
        int left = 0;
        int right = distance;
        int mid;
        int nn;
        int start;
        
        while(left <= right){
            nn = 0;
            mid = (left+right)/2;   
            start = 0;
          
            for(int i = 0; i < rocks.length; i++){
                if(rocks[i] - start < mid) nn++;
                else  start = rocks[i];
            }
            if(distance - start < mid) nn++;
          
            if(nn > n)  right = mid-1;
            else {
                left =  mid+1;
                answer = answer < mid ? mid : answer;
            }
        }
        
        return answer;
    }
}
