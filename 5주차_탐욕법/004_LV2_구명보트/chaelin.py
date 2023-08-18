# def solution(people, limit):
#     answer = 0
#     people = sorted(people)
#     print(people)
    
#     while len(people) > 0:
#         a = people[0]
#         b = people[-1]
#         if a+b > limit:
#             if a <= limit:
#                 answer += 1
#                 people.pop(0)
#             if b <= limit:
#                 if len(people) > 0:
#                     answer += 1
#                     people.pop(-1)
#         else:
#             answer += 1
#             people.pop(0)
#             people.pop(-1)
#         print(people, a, b, answer)
#     return answer


# def solution(people, limit):
#     answer = 0
#     people = sorted(people)
#     # print(people)
#     # [50, 50, 70, 80]
#     while len(people) > 0:
#         a = people[0]
#         b = people[-1]
#         if a+b > limit:
#             if a > b and len(people) > 0:
#                 answer += 1
#                 people.pop(0)
#             if b > a and len(people) > 0:
#                 answer += 1
#                 people.pop(-1)
#         else:
#             answer += 1
#             if len(people) > 0:
#                 people.pop(0)
#             if len(people) > 0:
#                 people.pop(-1)
#         # print(people, a, b, answer)
#     return answer


from collections import deque
def solution(people, limit):
    answer = 0
    people_deq = deque(sorted(people))
    while len(people_deq) > 0:
        a = people_deq[0]
        b = people_deq[-1]
        if a+b > limit:
            answer += 1
            people_deq.pop()
        else:
            answer += 1
            people_deq.popleft()
            if len(people_deq) > 0:
                people_deq.pop()
    return answer
