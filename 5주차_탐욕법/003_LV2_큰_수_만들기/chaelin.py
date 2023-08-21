# def combination(arr, n):
#     result = []
    
#     if n == 0:
#         return [[]]
#     for i in range(0, len(arr)):
#         num = arr[i]
#         result_arr = arr[i+1:]
#         for combi in combination(result_arr, n-1):
#             result.append([num]+combi)
#         print(result)
#     return result
    

# def solution(number, k):
#     answer = ''
#     num_list = [int(num) for num in number]
#     # print(num_list)
#     comb_list = combination(num_list, len(number)-k)
#     # print(comb_list)
    
#     convert_comb_list = []
#     for num in comb_list:
#         str_int = ""
#         for n in num:
#             str_int += str(n)
#         convert_comb_list.append(int(str_int))
#     # print(convert_comb_list)
#     answer = str(max(convert_comb_list))
#     return answer

# 굳이 문자열을 옮기지 않고, 매번 시작점을 가리키는 변수를 유지하시면 매우 빠르게 해결가능합니다.
# 가장 빠른 방법은 number 문자열을 건드리지 않고 index 로만 접근하는 방법인 것 같네요.
# 추가적으로 9가 나오면 멈추는 최적화정도는 필수입니다.

# 시간초과났지만 어쨌든 한데까지..ㅠ
def solution(number, k):
    answer = 0
    
    num = ""
    while len(num) != len(number)-k:
        max = 0
        idx = 0
        for i in range(len(number)-k-len(num)):
            if max < int(number[i]):
                max = int(number[i])
                # num += str(max)
                idx = i
        print(idx, num)
        num += number[idx]
    return answer
