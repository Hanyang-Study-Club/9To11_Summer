def solution(numbers):
    # 두 수를 붙였을 때 큰 방향으로 붙이면 된다
    answer = ''
    
    str_numbers = []
    origin_numbers = {}
    for num in numbers:
        str_numbers.append(str(num)*3)
        origin_numbers[str(num)*3] = str(num)
    str_numbers = sorted(str_numbers, reverse=True)
    # print(str_numbers, origin_numbers)
    
    for str_num in str_numbers:
        answer += origin_numbers[str_num]
    
    return str(int(answer))
