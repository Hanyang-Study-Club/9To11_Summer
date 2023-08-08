import java.util.*;

class Solution {
    public int[] solution(int[] answers) {        
        int[] one = {1,2,3,4,5};
        int[] two = {2,1,2,3,2,4,2,5};
        int[] three = {3,3,1,1,2,2,4,4,5,5};
         
        int c[] = new int[3];

        for(int i = 0; i < answers.length; i++){
            if(one[i%5] == answers[i])  c[0]++;  
            if(two[i%8] == answers[i]) c[1]++;
            if(three[i%10] == answers[i]) c[2]++;
        }
        
        int max = Arrays.stream(c).max().getAsInt();     
        
        ArrayList<Integer> temp = new ArrayList<Integer>();
        
        for(int i = 0 ; i < 3 ; i++){
            if(max == c[i]) temp.add(i+1);
        }

        int[] answer = temp.stream().mapToInt(i -> i).toArray();
        
        return answer;
    }
}
