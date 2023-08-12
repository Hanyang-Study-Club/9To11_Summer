import java.util.*;
class Solution {
    HashMap<Integer,ArrayList<Integer>> tree; 
    int N;
    boolean selected[];
    int result;
    
    public void dfs(int k){
        if(!selected[k]){
            selected[k] = true;
            result++;
            ArrayList<Integer> temp = tree.get(k);
            for(int i = 0 ; i < temp.size(); i++){
                dfs(temp.get(i));    
            }
            selected[k] = false;
        }    
    }
    
    public int solution(int n, int[][] wires) {
        int answer = n;
        
        N=n;
        selected = new boolean[n];
        tree = new HashMap<Integer,ArrayList<Integer>>();
        ArrayList<Integer> temp;// 임시   

        //트리로 만들기
        for(int i = 0; i < wires.length; i++){
            int node1 = wires[i][0] -1;
            int node2 = wires[i][1] -1;
            
            temp = new ArrayList<Integer>();
            temp = tree.getOrDefault(Integer.valueOf(node1), temp);
            temp.add(node2);
            tree.put(node1, temp);
            
            temp = new ArrayList<Integer>();
            temp = tree.getOrDefault(Integer.valueOf(node2), temp);
            temp.add(node1);
            tree.put(node2, temp);
            
        }
        
        for(int i = 0; i < wires.length; i++){
            int node1 = wires[i][0] -1;
            int node2 = wires[i][1] -1;
            selected[node1] = true;
            dfs(node2);
            int r2 = Math.abs(N-result*2);
            if(answer > r2) answer = r2;
            selected[node1] = false;
            result = 0;
        }
        
        
        return answer;
    }
}
