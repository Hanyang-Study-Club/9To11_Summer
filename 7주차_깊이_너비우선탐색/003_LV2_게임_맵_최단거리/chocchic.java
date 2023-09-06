import java.util.*;
class Solution {

    public int solution(int[][] maps) {
        int[][] move = {{-1,0},{1,0},{0,-1},{0,1}};
        
        int y = maps.length-1;
        int x = maps[0].length-1;
        
        int[][] selected = new int[y+1][x+1];
        selected[0][0] = 1;
        
        Queue<int[]> que = new LinkedList<>();
        int[] init = {0,0};
        que.add(init);
        
        while(!que.isEmpty()){
            int[] cur = que.poll();
            int n = cur[0];
            int m = cur[1];
            for(int[] mo : move){
                int new_y = mo[0] + n;
                int new_x = mo[1] + m;
                if(y >= new_y && new_y >= 0 && x >= new_x && new_x >= 0){
                    int[] temp_que = {new_y, new_x};
                    if(maps[new_y][new_x] == 1 && selected[new_y][new_x]  == 0) {
                        que.add(temp_que);
                        selected[new_y][new_x] = selected[n][m] + 1;   
                    }
                }
            }
        }
        
        return selected[y][x] > 0 ? selected[y][x] : -1;
    }
}
