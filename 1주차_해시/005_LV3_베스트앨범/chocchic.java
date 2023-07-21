import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        
        Map<String, Integer> genres_rank = new HashMap<String, Integer>();
        Map<String, Map<Integer,Integer>> genres_grp = new HashMap<String, Map<Integer,Integer>>();
        Map<Integer, Integer> temp_map;
        
        for(int i = 0; i < genres.length; i++){
            temp_map = new HashMap<Integer, Integer>();
            genres_rank.put(genres[i], genres_rank.getOrDefault(genres[i],0)+plays[i]);
            if(genres_grp.containsKey(genres[i])){
                temp_map = genres_grp.get(genres[i]);
            }
            temp_map.put(i,plays[i]);
            genres_grp.put(genres[i],temp_map);
        }
        
        // 장르별로 재생횟수 정렬
        List<Map.Entry<String, Integer>> entryList = new LinkedList<>(genres_rank.entrySet());
        entryList.sort(Map.Entry.comparingByValue(Comparator.reverseOrder()));        
        
  
        // 재생횟수별로 정렬된 (장르 : 플레이 횟수) 쌍으로 이루이어진 entryList의 entry 값을 가져옴 
        for(Map.Entry<String, Integer> entry : entryList){
            temp_map = new HashMap<Integer, Integer>();
            String genre = entry.getKey();
            
            List<Map.Entry<Integer, Integer>> eL2 = new LinkedList<>(genres_grp.get(genre).entrySet());
           
            if(eL2.size() > 1){
                eL2.sort(Map.Entry.comparingByValue(Comparator.reverseOrder()));   // 내림차순 정렬
                for(int i = 0; i < 2 ; i++){
                    int N = answer.length;
                    answer = Arrays.copyOf(answer, N + 1);
                    answer[N] = eL2.get(i).getKey();    
                }
            }else{
                int N = answer.length;
                    answer = Arrays.copyOf(answer, N + 1);
                    answer[N] = eL2.get(0).getKey();            
            }            
        }
        
        return answer;
    }
}
