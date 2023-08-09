class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
                
        int tot = brown + yellow ; // 카펫 전체 칸
                
        for(int i = 3; i <= tot/2 ; i++){ // 최소가 8,1 이기 때문에 3부터 시작해도 됨. 똑같은 수 두번곱하는 경우까지만 확인
            if(tot %i == 0 && ((i-2) * ((tot / i) - 2)) == yellow) {
                answer[0] = i;
                answer[1] = tot/i;         
            }
        }
        
        return answer;
    }
}
