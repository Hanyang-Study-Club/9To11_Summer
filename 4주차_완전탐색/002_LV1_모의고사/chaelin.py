import math 

def solution(answers):
    answer = []
    score = [0,0,0]
    
    soopoza_1 = [1, 2, 3, 4, 5] 
    while len(answers) > len(soopoza_1):
        soopoza_1 += [1, 2, 3, 4, 5]
    soopoza_2 = [2, 1, 2, 3, 2, 4, 2, 5]
    while len(answers) > len(soopoza_2):
        soopoza_2 += [2, 1, 2, 3, 2, 4, 2, 5]
    soopoza_3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    while len(answers) > len(soopoza_3):
        soopoza_3 += [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    # print(soopoza_1, soopoza_2, soopoza_3)
    
    idx = 0
    for soo1, soo2, soo3 in zip(soopoza_1, soopoza_2, soopoza_3):
        
        if idx < len(answers):
            # print(soo1,soo2,soo3, answers[idx])
            if answers[idx] == soo1:
                score[0] += 1
            if answers[idx] == soo2:
                score[1] += 1
            if answers[idx] == soo3:
                score[2] += 1
        idx += 1
    # print(score)
    
    max_score = max(score)

    soo1 = score[0]
    if soo1 == max_score: 
        answer.append(1)
    soo2 = score[1]
    if soo2 == max_score:
        answer.append(2)
    soo3 = score[2]
    if soo3 == max_score:
        answer.append(3)
    
    return sorted(answer)
