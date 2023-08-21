def dfs(graph, start_node, dontgo):
    ## 기본은 항상 두개의 리스트를 별도로 관리해주는 것
    need_visited, visited = list(), list()
    ## 시작 노드를 시정하기 
    need_visited.append(start_node)
    
    ## 만약 아직도 방문이 필요한 노드가 있다면,
    while need_visited:
        ## 그 중에서 가장 마지막 데이터를 추출 (스택 구조의 활용)
        node = need_visited.pop()
        
        ## 만약 그 노드가 방문한 목록에 없다면
        if node not in visited:
            ## 방문한 목록에 추가하기 
            visited.append(node)
            ## 그 노드에 연결된 노드를 
            # need_visited.extend(graph[node])
            for gn in graph[node]:
                if gn not in dontgo or node not in dontgo:
                    need_visited.append(gn)
    return visited

def solution(n, wires):
    graph = {}

    for wire in wires:
        a, b = wire
        if a not in graph:
            graph[a] = [b]
        if b not in graph:
            graph[b] = [a]
        if a in graph and b in graph:
            graph[a].append(b)
            graph[b].append(a)
    
    dup_graph = {}
    for key in graph:
        dup_graph[key] = set(graph[key])
    # print(dup_graph)
    
    # 2 를 포함 하는 트리
    # 2 를 포함하지 않는 (1 을 포함하는 트리 )
    # 1 번트리의 노드개수 : 3
    # 2 번트리의 노드개수 4
    # abs(3-4)
    min_gap = len(dup_graph)
    for node in dup_graph:
        for num in dup_graph[node]:
            dontgo = [node, num]
            result = dfs(dup_graph, node, dontgo)
            # print(dontgo, result)
            first_graph_len = len(result)
            second_graph_len = len(dup_graph) - len(result)
            gap = abs(first_graph_len - second_graph_len)
            if min_gap > gap:
                min_gap = gap
            # print(first_graph_len, second_graph_len)
    return min_gap
