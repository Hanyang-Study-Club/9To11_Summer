class Solution {
    public String solution(String number, int k) {
        String answer = "";
        int max = 0;
        int max_idx = 0;   
        
        char[] num = number.toCharArray();
        
        while(k > 0){
            if (answer.length() == number.length() - k) break;
            
            int start = max_idx;
            int end = start + k + 1;
            for(int i = start; i < end; i++){
                int temp = num[i] - '0';
                if(max < temp) {
                    max = temp;
                    max_idx = i;
                }
            }
            System.out.println();
            
            answer+= num[max_idx] ;
            int gap = max_idx - start;
            k = k - gap;
            max_idx++;
            max = 0;
            
        }
        
        if(answer.length() != number.length() - k){
            answer +=number.substring(max_idx);
        }
        
        
        
        return answer;
    }
}
