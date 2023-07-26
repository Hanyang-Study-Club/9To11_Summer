import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        if(s.length() % 2 != 0) return false;
        if(s.charAt(0) == ')' || s.charAt(s.length()-1) == '(') return false;
    
        int cnt = 0;
    
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(c == '(') {
                cnt++;     
            }
            else {
                cnt--;
                if(cnt < 0) return false;
            }
        }
        answer = cnt > 0 ?false:true;
        return answer;
    }
}