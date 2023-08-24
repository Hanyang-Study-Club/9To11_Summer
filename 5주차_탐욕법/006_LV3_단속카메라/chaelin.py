def solution(routes):
    answer = 0
    # [-14,-5] -> (-14, '1', 's'), (-5, '1', 'e')
    
    sort_routes = []
    idx = 0
    for route in routes:
        sort_routes.append([route[0], idx, "s"])
        sort_routes.append([route[1], idx, "e"])
        idx += 1
    # sort_routes = sorted(sort_routes)
    # print(sort_routes)
    sort_routes.sort(key = lambda x:(x[0], -ord(x[2])))
    # x[0]을 기준으로 정렬하고 같은 경우 x[2]값이 아스키 값 상으로 내림차순이 되도록 정렬함. s가 e보다 뒤이므로 -로 내림차순 해야!!!
    # print(sort_routes)
    
    # 만약 여태 지나간(이미 체크됨) 차량들이 전체 차량의 수와 같으면 break
    # 인덱스를 확인하여(a[1]) 이미 체크된 차량일 경우 다시 확인할 필요 없으니 continue
    # 만약 's'가 나타날 경우(어떤 차량의 시작점일 경우) 
    #   '현재 체크 중인 차량들' 에 현재 차량 인덱스 append
    # 만약 'e'가 나타날 경우(어떤 차량의 마지막점일 경우) 
    #   '현재 체크 중인 차량들'을 전부 '이미 체크됨'에 넣음.
    #   현재 지점이 단속 카메라를 설치할 지점이므로 answer += 1
    check = []
    check_finish = []
    for route in sort_routes:
        # print(route, check, check_finish, answer)
        if len(check_finish) == len(routes):
            break
        if route[1] in check_finish:
            continue
        if route[2] == "s":
            check.append(route[1])
        if route[2] == "e":
            check_finish+= check
            check = []
            answer += 1
    # print(check, check_finish, answer)
    return answer
