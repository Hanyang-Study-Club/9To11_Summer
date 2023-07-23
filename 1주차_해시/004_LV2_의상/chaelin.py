def solution(clothes):
    answer = 1
    
    cloth_dict = {}
    for cloth in clothes:
        if cloth[1] not in cloth_dict.keys():
            cloth_dict[cloth[1]] = [cloth[0]]
        else:
            cloth_dict[cloth[1]].append(cloth[0])
            
    for value in cloth_dict.values():
        answer *=(len(value)+1)
    answer -=1
    return answer
