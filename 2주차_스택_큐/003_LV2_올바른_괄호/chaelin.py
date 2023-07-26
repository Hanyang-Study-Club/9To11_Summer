def solution(s):
    answer = True
    
    stack = []
    string_list = list(s)
    for string in string_list:
        if string == "(":
            stack.append(string)
        if string == ")":
            if len(stack) == 0:
                stack.append(string)
            elif stack[-1] != "(":
                stack.append(string)
            else:
                stack.pop()
            # print(string, stack)
    if len(stack) > 0:
        answer = False
    return answer
