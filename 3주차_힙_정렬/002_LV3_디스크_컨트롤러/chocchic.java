import java.util.*;

class Job{
	int start;
    int time;
    
	Job(int start, int time){
		this.start = start;
		this.time = time;
	}
}

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;

        // 도중에 들어와서 대기를 해야하는 것들 -> 요청시간과 실제 시작시간과 차이가 있음
        PriorityQueue<Job> disc = new PriorityQueue<>(new Comparator<Job>() {
            @Override
            public int compare(Job j1, Job j2) {
                if(j1.time > j2.time) return 1;
                return -1;
            }
        });
        
        int starts = 0;
        
        Arrays.sort(jobs,new Comparator<int[]>() {
           @Override
           public int compare(int[] o1, int[] o2) {
                  return o1[0] > o2[0] ? 1 : -1;
           }
        }); 
        
        starts = jobs[0][0] + jobs[0][1];
        answer = jobs[0][1];
        
        for(int i = 1;;){
            
            if( jobs.length > i  && jobs[i][0] <= starts){
                Job temp = new Job(jobs[i][0], jobs[i][1]);
                disc.offer(temp);
                i++;
                //System.out.println(temp.start+"::"+temp.time);
            }else{
                // disc에 있는 거 하나만 꺼내서 계산
                if(!disc.isEmpty()){
                    Job cur_job = disc.poll();
                    System.out.println(cur_job.start+"::"+cur_job.time);
                    answer+= starts - cur_job.start + cur_job.time;
                    starts += cur_job.time;
                }else{
                    if(jobs.length > i){
                        Job temp = new Job(jobs[i][0], jobs[i][1]);
                        starts = jobs[i][0];
                        disc.offer(temp);
                        i++;
                    }
                    else break;
                    //System.out.println(temp.start+"::"+temp.time);
                }
                
            }
        }
        
        return answer / jobs.length;
    }
}
