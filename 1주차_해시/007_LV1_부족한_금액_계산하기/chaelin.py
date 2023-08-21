def solution(price, money, count):
    answer = -1
    
    sum_money = 0
    for i in range(count):
        sum_money += price * (i+1)
    # print(sum_money)
    if sum_money <= money:
        answer = 0
    else:
        answer = sum_money - money
    
    return answer
