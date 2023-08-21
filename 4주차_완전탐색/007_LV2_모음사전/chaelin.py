
# def dfs(total_cnt, cnt, w, answer_word):
#     word_list = []
#     words = "AEIOU"
#     if cnt == 5:
#         return word_list
#     for i in range(len(words)):
#         word_list.append(w + words[i])
#         total_cnt += 1
#         print(word_list)
#         if answer_word in word_list:
#             print(word_list, total_cnt)
#             return total_cnt
#         dfs(total_cnt, cnt+1, w + words[i], answer_word)
            
# def solution(word):
#     answer = 0
#     total_cnt = 0
#     result = dfs(total_cnt, 0,"", word)
#     print(result)
#     # return word_list.index(word)+1
#     return answer

from itertools import product

def solution(word):
    char = ["A","E","I","O","U"]
    tmp = []
    for i in range(1, 6):
        for j in product(char,repeat=i):
            tmp.append(''.join(list(j)))
    tmp.sort()
    return tmp.index(word)+1
