def solution(genres, plays):
    answer = []
    
    playlist = {}
    for i in range(len(genres)):
        if genres[i] in playlist.keys():
            playlist[genres[i]].append(plays[i])
        else:
            playlist[genres[i]]=[plays[i]]
    # print(playlist)
    
    genre_sum_dict = {}
    for genre in playlist:
        genre_sum_dict[genre] = sum(playlist[genre])
    
    sorted_genre_sum = sorted(genre_sum_dict.items(), key = lambda item: item[1], reverse = True)
    # print(genre_sum_dict)
    # print(sorted_genre_sum)
    
    plays_dict = {}
    for idx in range(len(plays)) :
        plays_dict[plays[idx]] = idx
    # print(plays_dict)
    for sgsd in sorted_genre_sum:
        genre = sgsd[0]
        sorted_playlist = sorted(playlist[genre], reverse=True)
        # print("sorted_playlist: " , sorted_playlist)
        if len(sorted_playlist) > 0:
            if len(sorted_playlist) == 0:
                answer.append(plays_dict[sorted_playlist[0]])
            else:
                answer.append(plays_dict[sorted_playlist[0]])
                answer.append(plays_dict[sorted_playlist[1]])
        
    # print(answer)
    
    
    return answer
