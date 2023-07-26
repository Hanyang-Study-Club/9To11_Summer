import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 1;

        int N = priorities.length;

        Queue<int[]> que = new LinkedList<int[]>();
        int[] temp;
        for(int i = 0 ; i < N ; i++){
            temp = new int[2];
            temp[0]=i;
            temp[1]=priorities[i];
            que.offer(temp);
        }
                
        Arrays.sort(priorities);
        
        Queue<int[]> que2 = new LinkedList<int[]>();
        int idx = 0;
        while(!que.isEmpty()){
            int max = priorities[N-1-idx];
            temp = que.poll();
            if(temp[1] != max) {
                que.offer(temp);
            }else{
                que2.offer(temp);
                idx++;
            }
        }
       
        while(!que2.isEmpty()){
            temp = que2.poll();
            if(temp[0] == location) break;
            answer++;
        }
        
        return answer;
    }
}