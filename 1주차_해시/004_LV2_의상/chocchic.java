import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        
        HashMap<String, Integer> c_map = new HashMap<String, Integer>();
        
        for(int i = 0 ; i < clothes.length; i++){
            String sort = clothes[i][1];
            
            c_map.put(sort, c_map.getOrDefault(sort,0)+1);
        }
        
        
        for(String key: c_map.keySet()){
            answer *= (c_map.get(key)+1);
        }
        
        return answer -1;
    }
}
