import heapq

def solution(scoville, K):
    # 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
    answer = 0
    
    heapq.heapify(scoville)
    while scoville[0] < K and len(scoville) >= 2:
        pop_scoville_1 = heapq.heappop(scoville)
        pop_scoville_2 = heapq.heappop(scoville)
        tmp_scoville = pop_scoville_1 + (pop_scoville_2 * 2)
        heapq.heappush(scoville, tmp_scoville)
        answer += 1
    
    for sco in scoville:
        if sco < K:
            answer = -1
            
    return answer
