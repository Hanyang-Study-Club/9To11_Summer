import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        
        
        Map<String, Integer> genres_rank = new HashMap<String, Integer>();
        Map<String, Integer[]> genres_grp = new HashMap<String, Integer[]>();
        
        for(int i = 0; i < genres.length; i++){
            genres_rank.put(genres[i], genres_rank.getOrDefault(genres[i],0)+plays[i]);
            Integer[] grp;
            if(genres_grp.containsKey(genres[i])){
                grp = genres_grp.get(genres[i]);
                if(plays[i] > plays[grp[0]]){
                    grp[1] = grp[0];
                    grp[0] = i;
                }else if(grp[1] == -1 || plays[i] > plays[grp[1]]){
                    grp[1] = i;
                }
            }else{
                grp = new Integer[] {i,-1};
            }
            
            genres_grp.put(genres[i],grp);
        }
        
        // 장르별로 재생횟수 정렬
        List<Map.Entry<String, Integer>> entryList = new LinkedList<>(genres_rank.entrySet());
        entryList.sort(Map.Entry.comparingByValue(Comparator.reverseOrder()));        
        
        int[] answer = {};
        // 재생횟수별로 정렬된 (장르 : 플레이 횟수) 쌍으로 이루이어진 entryList의 entry 값을 가져옴 
        for(Map.Entry<String, Integer> entry : entryList){
          // 자바에서는 배열 동적 생성이 불가능하므로 기존 answer의 길이를 가져와서 answer 재할당
            int N = answer.length;
            answer = Arrays.copyOf(answer, N + 1);
            answer[N] = genres_grp.get(entry.getKey())[0];
            if(genres_grp.get(entry.getKey())[1] != -1){
                N = answer.length;
                answer = Arrays.copyOf(answer, N + 1);
                answer[N] = genres_grp.get(entry.getKey())[1];
            }
        }
        
        return answer;
    }
}
