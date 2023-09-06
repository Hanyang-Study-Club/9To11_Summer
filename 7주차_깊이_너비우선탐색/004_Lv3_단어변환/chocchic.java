//BFS
import java.util.*;
class Solution {
    public int solution(String begin, String target, String[] words) {     
        Queue<String> que = new LinkedList<>();
        HashMap<String, Integer> selected = new HashMap<String, Integer>();
        
        que.add(begin);
        selected.put(begin,0);
        
        while(!que.isEmpty()){
            String que_word = que.poll();
            
            for(int i = 0; i < words.length; i++){
                String cur_words = words[i];
                int diff = 0;
                for(int cAt = 0; cAt < cur_words.length(); cAt++){
                    if(que_word.charAt(cAt) != cur_words.charAt(cAt)) diff++;
                }
                int cnt = selected.getOrDefault(cur_words,0);
                int cnt2 = selected.getOrDefault(que_word,0)+1;
                if(diff == 1 && cnt == 0) {
                    que.add(cur_words);
                    selected.put(cur_words, cnt2);
                }
            }

        }
        
        return selected.getOrDefault(target,0);
    }
}
