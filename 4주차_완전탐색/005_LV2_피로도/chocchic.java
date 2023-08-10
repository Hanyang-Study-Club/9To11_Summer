class Solution {
    boolean selected[];
    int[][] dungeons2;
    int max;
    
    public void dfs(int cur_fatigue, int result){

        for(int i = 0; i < selected.length; i++ ){
            if(selected[i] != true && cur_fatigue >= dungeons2[i][0]){            
                selected[i] = true;
                int n_fatigue = cur_fatigue-dungeons2[i][1];
                int n_result = result+1;
                dfs(n_fatigue, n_result); // 재귀 호출
                selected[i] = false;
            }    
        }
        if(max < result) max = result;
    }
    
    public int solution(int k, int[][] dungeons) {
        
        selected = new boolean[dungeons.length];
        dungeons2 = dungeons;
        
        dfs(k,0);

        return max;
    }
    
}
