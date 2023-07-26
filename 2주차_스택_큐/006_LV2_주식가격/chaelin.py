def solution(prices):
    answer = [0 for _ in range(len(prices))]
    for i in range(0, len(prices)):
        false_cnt = 0
        for j in range(i+1, len(prices)):
            curr_price = prices[i]
            compare_price = prices[j]
            if curr_price <= compare_price and false_cnt == 0:
                answer[i]+=1
            else:
                false_cnt+=1
                if false_cnt == 1:
                    answer[i]+=1
                break
    return answer

