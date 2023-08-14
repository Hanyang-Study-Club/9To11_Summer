import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        HashSet<Integer> lost2 = new HashSet<Integer>();
        HashSet<Integer> re2 = new HashSet<Integer>();
        for(int l  = 0 ;l < lost.length; l++){
            lost2.add(lost[l]);
        }
        
        for(int r = 0; r < reserve.length; r++){
            if(lost2.contains(reserve[r])) lost2.remove(reserve[r]); // 잃어버리기도 했으면 여분 x이므로 빌려줄 수 없음.
            else re2.add(reserve[r]);
        }
        
        
        for(int i = 1; i <= n ; i ++){
            if(lost2.contains(i)){
                if(re2.contains(i-1)){
                    re2.remove(i-1);
                    answer++;
                }
                else if(re2.remove(i+1)){
                    re2.remove(i+1);
                    answer++;
                }
            }else{
                answer++;
            }
        }
        
        return answer;
    }
}
