import java.util.*;
class Solution {
    boolean selected[];
    int N;
    int[][] com;

    public void dfs(int i){
        for(int j = 0; j < N; j++){
            if(i != j && selected[j] != true && com[i][j] == 1) {
                selected[j] = true;
                dfs(j);
            }
        }
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
     
        N = n;
        selected = new boolean[n];
        com = computers;
        
        for(int i = 0; i < n; i++){
            if(selected[i] != true){
                selected[i] = true;
                answer++;
                dfs(i);            
            }
        }

        return answer;
    }
}
