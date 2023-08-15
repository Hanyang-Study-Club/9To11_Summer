def solution(n, lost, reserve):
    reserve = sorted(reserve)
    lost = sorted(lost)
    answer = 0
    can_borrow = {}
    for num in lost:
        can_borrow[num] = []
        if num in reserve:
            can_borrow[num].append(num)
            continue
        elif num > 1 and num < n:
            if num-1 not in lost and num-1 in reserve:
                can_borrow[num].append(num-1)
            if num+1 not in lost and num+1 in reserve:
                can_borrow[num].append(num+1)
        elif num == 1 and num+1 not in lost and num+1 in reserve:
            can_borrow[num] = [num+1]
        elif num == n and num-1 not in lost and num-1 in reserve:
            can_borrow[num] = [num-1]
    # print(can_borrow)
    
    borrow = []
    for num in can_borrow:
        if len(can_borrow[num]) > 0:
            if len(can_borrow[num]) == 1:
                if can_borrow[num][0] not in borrow:
                    borrow.append(can_borrow[num][0])
            if len(can_borrow[num]) == 2:
                if can_borrow[num][0] not in borrow:
                    borrow.append(can_borrow[num][0])
                    continue
                if can_borrow[num][1] not in borrow:
                    borrow.append(can_borrow[num][1])
                    continue
    # print(borrow)
    # print(len(borrow) + len(reserve) + (n - len(lost) - len(reserve)))
    answer = len(borrow) + len(reserve)+(n - len(lost) - len(reserve))
    return answer
