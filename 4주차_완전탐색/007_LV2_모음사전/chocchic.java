class Solution {
    String[] vowel = {"A","E","I","O","U"};
    String w;
    
    int temp = 0;
    int answer;
    
    public void dfs(String cur_word){
        if(w.equals(cur_word)){
            answer = temp;
          return;          
        } 
        
        if(cur_word.length() == 5) return;
        
        for(int v = 0; v < 5; v++){
            String n_cur_word = cur_word + vowel[v];
            temp++;
            dfs(n_cur_word);
        }
        
    }
    
    public int solution(String word) {
        answer = 0;
        w = word;
        
        dfs("");
        
        return answer;
    }
}
