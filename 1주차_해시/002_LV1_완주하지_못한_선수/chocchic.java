import java.util.*; 

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        HashMap<String,Integer> part_set = new HashMap<String,Integer>();
        for(int i = 0; i < participant.length; i++){
            int cnt = part_set.getOrDefault(participant[i],0)+1;
            part_set.put(participant[i],cnt);
        }
                
        for( String key : completion){
            int cnt = part_set.get(key)-1;
            part_set.put(key,cnt);
        }
            
        for (String part : part_set.keySet()){
            if(part_set.get(part) > 0 ){
                answer = part;    
            }
        }
        
        return answer;
    }
}
