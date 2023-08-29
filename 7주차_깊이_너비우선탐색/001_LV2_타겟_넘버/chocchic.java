class Solution {
    int[] nums;
    boolean selected[];
    int answer;
    int t;
    int size;
    public void dfs(int n, int num){
        if(n == size) {
            if(num == t) answer++;
            return;
        }
        int temp1 = num-nums[n];
        int temp2 = num+nums[n];
        int n_t = n+1;
        dfs(n_t,temp1);
        dfs(n_t,temp2);

    }
        
    public int solution(int[] numbers, int target) {
        answer = 0;
        
        size = numbers.length;
        selected = new boolean[size];
        nums = numbers;
        t=target;
        
        dfs(0,0);
        
        return answer;
    }
}
