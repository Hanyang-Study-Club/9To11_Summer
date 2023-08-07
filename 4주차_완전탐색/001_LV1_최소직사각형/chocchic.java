import java.util.*;
class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        
        int x =0, y = 0;
        for(int i = 0 ; i < sizes.length; i++){
            Arrays.sort(sizes[i]);
            if(x < sizes[i][0]) x = sizes[i][0];
            if(y < sizes[i][1]) y = sizes[i][1];
        }
        
        
        return x*y;
    }
}
