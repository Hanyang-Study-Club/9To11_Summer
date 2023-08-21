from itertools import permutations

def is_prime(num):
    if num == 0 or num == 1:
        return False
    for i in range(2,num):
        if num % i == 0:
            return False
    return True

def solution(numbers):
    answer = 0
    num_list = []
    
    for num in numbers:
        num_list.append(num)
    # print(num_list)
    
    perm_list = []
    for i in range(len(num_list)):
        sub_perm_list = list(permutations(num_list, i+1))
        # print(sub_perm_list)
        num = ""
        for sub_num in sub_perm_list:
            for sn in sub_num:
                num+=sn
            # print(int(num))
            perm_list.append(int(num))
            num = ""
    # print(set(perm_list))
    for prime_candidate in set(perm_list):
        if is_prime(prime_candidate):
            answer += 1
        # print("><!!",is_prime(prime_candidate))
    return answer
