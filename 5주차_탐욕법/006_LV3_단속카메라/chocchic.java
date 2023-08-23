import java.util.*;
class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        
        Arrays.sort(routes, (o1, o2) -> Integer.compare(o1[1], o2[1]));
        
        int camera = routes[0][0]-1; // 끝나는 지점이 젤 빠른 경로의 시작점        
        
        for (int i = 0 ;  i < routes.length; i++){
            if(camera < routes[i][0]){
                answer += 1;
                camera = routes[i][1]; 
            }
            
        }
        
        return answer;
    }
}
