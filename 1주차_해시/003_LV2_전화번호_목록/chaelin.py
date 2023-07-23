def solution(phone_book):
    answer = True

    # for num in phone_book:
    #     for num_compare in phone_book:
    #         if num != num_compare:
    #             if num == num_compare[0:len(num)]:
    #                 answer = False
    #                 return answer
    
    # for p1, p2 in zip(phone_book, phone_book[1:]):
    #     print(p1, p2)
    
#     pb_dict = {}
#     for pb in phone_book:
#         pb_dict[pb] = 1
#     print(pb_dict)
    
#     for pb in phone_book:
#         pb_dict.pop(pb)
#         print(pb, pb_dict)
#         if pb in pb_dict:
#             answer=False
#             return answer
#         pb_dict[pb] = 1

    phone_book = sorted(phone_book)
    for i in range(len(phone_book)-1):
        if phone_book[i] == phone_book[i+1][0:len(phone_book[i])]:
            answer = False
            return answer

    return answer
