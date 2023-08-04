import java.util.*;
class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        int N = citations.length;
        Arrays.sort(citations);
        
        if(citations[N-1] == 0) return 0;
        int temp;
        
        for(int h = citations[0]; h <= citations[N-1]; h++){
            temp=0;
            for(int idx = 0; idx < N; idx++){
                if(citations[idx] >= h) temp++;
            }
            if(h >= temp && answer < temp) answer = temp;
        }
        
        return answer;
    }
}
