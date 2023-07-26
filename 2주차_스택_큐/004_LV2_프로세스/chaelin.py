def solution(priorities, location):
    answer = 0
    
    process = [i for i in range(len(priorities))]
    # print(process)
    # print(priorities)
    while len(priorities) > 0:
        location_queue = ""
        get_queue = priorities.pop(0)
        get_process = process.pop(0)

        if len(priorities) > 0 and get_queue < max(priorities):
            priorities.append(get_queue)
            process.append(get_process)
            # print(priorities, process, get_queue, max(priorities))
        else:
            location_queue = get_process
            answer += 1
        
        if location_queue == location:
            return answer
        
    
    return answer
