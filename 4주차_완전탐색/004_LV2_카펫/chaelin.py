def solution(brown, yellow):
    answer = []
    width_height = []
    
    total_color = brown + yellow
    for i in range(1, total_color+1):
        sub_width_height = []
        if total_color % i == 0:
            if i > 2 and total_color//i > 2 and i >= total_color//i:
                sub_width_height.append(i)
                sub_width_height.append(total_color//i)
                width_height.append(sub_width_height)
    # print(width_height)
    
    for wh in width_height:
        if yellow == (wh[0]-2) * (wh[1]-2):
            answer.append(wh[0])
            answer.append(wh[1])
    return answer
