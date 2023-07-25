def solution(arr):
    answer = []
    
    while len(arr) > 0:
        num = arr.pop()
        if len(answer) == 0:
            answer.append(num)
        if num != answer[-1]:
            answer.append(num)
        
    answer.reverse()
    return answer
