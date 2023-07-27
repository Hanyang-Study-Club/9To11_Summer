class Solution {
    public int[] solution(int[] prices) {
        int N = prices.length;
        int[] answer = new int[N];
        
        for(int i = 0; i < N-1 ; i++){
            int cur = prices[i];
            for(int j = i+1; j < N; j++){
                int next = prices[j];
                if(cur <= next) answer[i]++;
                else {
                    answer[i]++;
                    break;
                }
            }
        }
        
        return answer;
    }
}