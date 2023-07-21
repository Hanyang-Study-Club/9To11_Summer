import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        List<String> p_al = Arrays.asList(phone_book);
        Collections.sort(p_al);
        
        for (int i = 0; i < p_al.size()-1; i++) { 		      
            String phone_i = p_al.get(i);
            String phone_i2 = p_al.get(i+1);
            if(phone_i2.startsWith(phone_i)) return false;            
        }   
        
        return answer;
    }
    
}
