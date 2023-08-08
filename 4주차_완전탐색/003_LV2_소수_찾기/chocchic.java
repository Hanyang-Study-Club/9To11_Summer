import java.util.*;

class Solution {
    String nums;
    HashSet<Integer> set;
    boolean selected[];
   
    public void dfs(String cur, int len) { 
            
        if(cur.length() == len) {  // 길이만큼 선택했으면 끝
            int cur_int = Integer.parseInt(cur);
            set.add(cur_int);
            return; 
        }

        for(int i = 0; i < nums.length(); i++){ 
            if(selected[i] != true){            
                selected[i] = true;
                String char2 = nums.charAt(i) +"";
                String temp = cur+char2;
                dfs(temp, len); // 재귀 호출
                selected[i] = false;
                
            } 
        }
    }
    
    public boolean isPrime(int n){
        if(n ==  2 || n == 3 ) return true;
        if(n == 1 || n == 0) return false;
        for(int i = 2; i < n ; i++ ) {
            if(n % i == 0) return false;
        }
        return true;
    }
    
    public int solution(String numbers) {
        int answer = 0;
                
        set = new HashSet<Integer>();
        nums = numbers;    
        selected = new boolean[numbers.length()];
        for(int len = 1 ; len <= numbers.length(); len++){
            dfs("",len);
        }
        
        Iterator<Integer> iter = set.iterator();
		while(iter.hasNext()) {
            Integer i1 = iter.next();
            int i2 = i1.intValue();
      			if(isPrime(i2))       answer++;                      
		}
        
        return answer;
    }
}
