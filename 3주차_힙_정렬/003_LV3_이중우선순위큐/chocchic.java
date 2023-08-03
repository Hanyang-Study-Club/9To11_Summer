import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        
        List<Integer> q = new ArrayList<>();
        
        for(int i = 0; i < operations.length; i++){
            String[] temp = operations[i].split(" ");
            if(temp[0].equals("I")){
                q.add(Integer.parseInt(temp[1]));
                Collections.sort(q);
            }else{ // temp[0] == "D"
                if(q.size() == 0 ) continue;
                if(temp[1].equals("1")) {
                     q.remove(q.size() - 1);
                }else{
                     q.remove(0);
                }
            }
        }
        if(q.size() > 0){
            answer[1] = q.get(0);
            answer[0] = q.get(q.size()-1);
        }
        
        return answer;
    }
}
