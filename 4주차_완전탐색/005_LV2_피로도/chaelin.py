from itertools import permutations

# def solution(k, dungeons):
#     answer = -1
#     order = []
#     save_k = k
#     for i in range(len(dungeons)):
#         sub_order = 0
#         prev_dungeon = dungeons[i]
#         if k >= prev_dungeon[0]:
#             k -= prev_dungeon[1]
#             sub_order += 1
#             print(k, sub_order)
#         for j in range(len(dungeons)):
#             if i != j:
#                 next_dungeon = dungeons[j]
                
#                 if k >= next_dungeon[0]:
#                     k -= next_dungeon[1]
#                     sub_order += 1
#                 print(k, sub_order, prev_dungeon, next_dungeon)
#         k = save_k
#     return answer


def solution(k, dungeons):
    answer = -1
    order = []
    save_k = k
    
    nCr = list(permutations(dungeons, len(dungeons)))
    # print(nCr)
    
    for perm in nCr:
        sub_order = 0
        for dungeon in list(perm):
            # print(dungeon)
            if k >= dungeon[0]:
                k -= dungeon[1]
                sub_order += 1
        # print("---")
        order.append(sub_order)
        k = save_k
    # print(order)
    answer = max(order)
    return answer
