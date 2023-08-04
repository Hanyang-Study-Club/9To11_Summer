import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        String[] nums = new String[numbers.length];
        for(int i = 0 ; i < numbers.length; i++){
            nums[i] = numbers[i]+"";
        }
        
        if(Integer.parseInt(nums[0]) == 0 && Integer.parseInt(nums[numbers.length -1]) == 0) return "0"; // 0 00 00 00 000 이런 식으로 0만 있으면 그냥 0임
        
        Arrays.sort(nums, new Comparator<String>(){
            @Override
            public int compare(String s1, String s2) {
                return (s2+s1).compareTo(s1+s2);
            }
        });   
        
        for(String s : nums){
            answer+=s;
        }
                
        return answer;
    }
}
