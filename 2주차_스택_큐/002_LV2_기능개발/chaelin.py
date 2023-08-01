# def solution(progresses, speeds):
#     answer = []
#     progress_100 = [0 for _ in range(len(progresses))]
    
#     for idx in range(len(progresses)):
#         progress = progresses[idx]
#         speed = speeds[idx]
#         # print(progress, speed)
        
#         while progress < 100:
#             progress += speed
#             progress_100[idx]+=1
#     print(progress_100)
    
#     deploy = 0
#     deploy_max = 0
#     for days in progresses:
#         # print("1", days, progress_100, deploy, answer)
#         pop_days = progress_100.pop(0)
#         print(deploy_max, pop_days)
               
#         if len(progress_100) == 0:
#             print("1")
#             deploy += 1
#             answer.append(deploy)
#         elif pop_days >= progress_100[0]:
#             print("2")
#             deploy += 1
#         else:
#             if deploy_max > progress_100[0]:
#                 print("3")
#                 deploy += 1
#                 print("if~", deploy_max, pop_days)
#             else:
#                 print("4")
#                 print("가나요??")
#                 deploy += 1
#                 answer.append(deploy)
#                 deploy = 0
#                 deploy_max = 0
                
#         if deploy_max <= pop_days: 
#             print("5")
#             deploy_max = pop_days 
#         # print("2", days, progress_100, deploy, answer)
    
#     return answer


def solution(progresses, speeds):
    answer = []
    
    day = 0
    deploy = 0
    while len(progresses) > 0:
        # print(progresses, deploy, answer)
        if progresses[0] + day*speeds[0] >= 100:
            progresses.pop(0)
            speeds.pop(0)
            deploy += 1
        else: # 개발 완료를 못함
            if deploy > 0: # 연속 배포 가능일을 놓침
                answer.append(deploy)
                deploy = 0
            day += 1
    answer.append(deploy)
    return answer
