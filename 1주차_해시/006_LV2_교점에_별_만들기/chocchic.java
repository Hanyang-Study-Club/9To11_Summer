import java.util.*;

class Solution {
    public String[] solution(int[][] line) {
       
        ArrayList<ArrayList <Long>> spot2 = new ArrayList<ArrayList <Long>>();
        long max_x = Long.MIN_VALUE; long max_y = Long.MIN_VALUE;
        long min_x = Long.MAX_VALUE; long min_y = Long.MAX_VALUE;
        
        for(int i = 0; i < line.length-1; i++){
            for(int j = i+1; j < line.length; j++){
                long A = line[i][0]; long B = line[i][1]; long E = line[i][2];
                long C = line[j][0]; long D = line[j][1]; long F = line[j][2];
                long IF = A*D - B*C;
                if(IF == 0) continue;
            
                long spot_x = (B*F - E*D) / IF;
                long spot_y = (E*C - A*F) / IF;
                if((B*F - E*D) % IF == 0 && (E*C - A*F) % IF == 0){
                    ArrayList<Long> temp = new ArrayList<>();
                    temp.add(spot_x);
                    temp.add(spot_y);
                    if(min_x > spot_x) min_x = spot_x;
                    if(min_y > spot_y) min_y = spot_y;
                    if(max_x < spot_x) max_x = spot_x;
                    if(max_y < spot_y) max_y = spot_y;
                    spot2.add(temp);
                }
            }
        }
                
        String temp = "";
        for(long x = min_x ; x <= max_x; x++){
            temp = temp.concat(".");
        }
        
        ArrayList<String> answer = new ArrayList<String>();
        
        for(long y = 0 ; y <= (max_y-min_y); y++){
            answer.add(temp);       
        }
        
        for(ArrayList<Long> i : spot2){
            Long temp2 = max_y - i.get(1);
            int cur_y = temp2.intValue();
            temp = answer.get(cur_y); // 실제 들어가있는 배열

            temp2 = i.get(0) - min_x; 
            int cur_x =  temp2.intValue();            
            temp = temp.substring(0, cur_x) + '*' + temp.substring(cur_x + 1);
            
           answer.set(cur_y, temp);
        }
        
        String[] answerArr = new String[answer.size()];
        answerArr = answer.toArray(answerArr);
        
        return answerArr;
    }
}
