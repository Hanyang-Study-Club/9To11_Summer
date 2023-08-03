import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for(int i = 0; i < commands.length; i++){
            int[] cur_command = commands[i];
            int[] temp = new int[cur_command[1] - cur_command[0]+1];
            for(int start = cur_command[0] - 1 ; start < cur_command[1]; start++){
                temp[start -cur_command[0] + 1 ] = array[start];                
            }
            Arrays.sort(temp);
            answer[i] = temp[cur_command[2]-1];
                
        }
        
        return answer;
    }
}
