import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        Arrays.sort(people);
        
        int small = 0;
        for(int big = people.length-1; big >= small ; big--){
            if(people[big] + people[small] <= limit){
                small++;
            }
            answer++;
        }
        
        return answer;
    }
}
