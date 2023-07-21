import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int N = nums.length;
        
        HashMap<Integer,Integer> nums_set = new HashMap<Integer,Integer>();
        for(int i = 0; i < N ; i++){
            int cnt = nums_set.getOrDefault(nums[i],0)+1;
            nums_set.put(nums[i],cnt);
        }
                
        if (nums_set.size() > (N/2)){
            answer = N/2;
        }else{
            answer = nums_set.size();
        }
        
        
        return answer;
    }
}
