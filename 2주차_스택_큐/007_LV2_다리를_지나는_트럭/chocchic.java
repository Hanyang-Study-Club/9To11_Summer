import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        
        Deque<int[]> que = new LinkedList<int[]>();
        int cur_w = 0;
        int cur_car = 0;
        int temp[] = new int[2];
        temp[0] = bridge_length; temp[1] = 0;
        que.offer(temp);
        
        for(int i = 0; i < truck_weights.length; i++){
            cur_car =  truck_weights[i];
            //temp = new int[2]; // temp[0] 은 트럭 배열의 idx, temp[1]은 트럭 무게
            
            if(cur_w+cur_car <= weight){
                temp = que.poll();
                if(temp[1] == 0) { // 앞에 공백있는지 확인 후 넣기
                    temp[0] = temp[0]-1;
                    if(temp[0] > 0)  que.push(temp);
                }else{
                    cur_w-=temp[1];
                }
                temp=new int[2];
                temp[0] = i; temp[1] = cur_car;
                que.offerLast(temp);
                
                cur_w += cur_car;
                answer++; // 차량 진입
            }else{
                while(true){
                    temp = que.poll();
                    
                    if(temp[1] != 0){
                        
                        cur_w-=temp[1];
                       answer++;
                   
                        if(cur_w+cur_car <= weight){
                            cur_w += cur_car;
                            temp[0] = i; temp[1] = cur_car;
                            que.offerLast(temp);
                            break;
                        }else{
                            temp[0] = 1; temp[1] = 0;
                            que.offerLast(temp);
                            //answer++;
                        }   
                    }else{
                        answer+=temp[0];
                        que.offerLast(temp);
                    }   
                }
            }
            
           
        }
            
        temp = new int[2];
        while(cur_w > 0) {
            
            temp = que.poll();
            cur_w -=temp[1];
            if(temp[1] == 0){
                answer+=temp[0];
            }else{
                answer++;
            }
        }
        
        return answer;
    }
}
