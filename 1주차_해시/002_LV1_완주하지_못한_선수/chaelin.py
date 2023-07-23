def solution(participant, completion):
    answer = ''
    
    part_dict = {}
    for part in participant:
        if part not in part_dict:
            part_dict[part] = 1
        else:
            part_dict[part] += 1
    
    for comp in completion:
        # if comp in participant: # -> part_dict에 이미 필요 최소 수량의 선수 이름이 다 들어있으므로 없어도됨
        part_dict[comp] -= 1
    
    for part in part_dict:
        if part_dict[part]==1:
            answer = part
    return answer
