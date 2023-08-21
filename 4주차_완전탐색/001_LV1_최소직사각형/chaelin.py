def solution(sizes):
    answer = 0
    prev_min_size = 0
    prev_max_size = 0
    for size in sizes:
        min_size = min(size)
        max_size = max(size)
        prev_min_size = max(prev_min_size, min_size)
        prev_max_size = max(prev_max_size, max_size)
    answer = prev_min_size * prev_max_size
    return answer
