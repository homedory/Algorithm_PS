def solution(m, musicinfos):
    answer = '(None)'
    
    music_list = [];
    
    for info in musicinfos:
        start, end, title, music = info.split(',')
        
        hour, minute = start.split(':')
        start_time = int(hour) * 60 + int(minute)
        
        hour, minute = end.split(':')
        end_time = int(hour) * 60 + int(minute)
        
        played_time = end_time - start_time
        
        played = ''
        
        idx = 0;
        music_len = len(music)
        
        for l in range(played_time):
            if idx >= music_len:
                idx = 0
            
            if idx + 1 < music_len and music[idx + 1] == '#':
                played = played + music[idx].lower()
                idx += 1
            else:
                played = played + music[idx]
                
            idx += 1
        
        
        music_list.append([played_time, title, played])
        
        
    max_len = 0
    
    m_ = ''
    
    m_len = len(m)
    
    idx = 0
    while idx < m_len:
        if idx + 1 < m_len and m[idx+1] == '#':
            m_ = m_ + m[idx].lower()
            idx += 1
        else:
            m_ = m_ + m[idx]
        idx += 1
        
    
    for music in music_list:
        if m_ in music[2] and max_len < music[0]:
            answer = music[1]
            max_len = music[0]
        
        
    
    return answer