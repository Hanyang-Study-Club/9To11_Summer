import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        
        Stack<Integer> s = new Stack<Integer>();
        List<Integer> list = new ArrayList<Integer>();
        
        for(int i = progresses.length-1; i >= 0; i--){
            s.push(progresses[i]);
        }
        
        int idx = 0;
        int ans = 0;
        while(!s.empty()){
            if(s.peek() >= 100){
                ans++;
                s.pop();
            } 
            else{
                if(ans > 0) {
                    list.add(ans);
                    idx += ans;
                    ans = 0;
                }
                int idx2 = idx;
                while(!s.empty()){
                    progresses[idx2] = s.pop()+speeds[idx2];
                    idx2++;
                }
                
                for(int i = progresses.length-1; i >= idx; i--){
                    s.push(progresses[i]);
                }
            }
        }
        list.add(ans);
        answer = list.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
}