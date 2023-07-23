def solution(nums):
    answer = 0
    
    nums_dict = {}
    cnt_limit = len(nums) // 2
    answer_dict = {}
    for num in nums:
        if num not in nums_dict.keys():
            nums_dict[num] = 1
        else:
            nums_dict[num] += 1
        if num not in answer_dict.keys() and len(answer_dict.keys()) < cnt_limit:
            answer_dict[num] = 1
    answer = len(answer_dict)
            
    return answer
