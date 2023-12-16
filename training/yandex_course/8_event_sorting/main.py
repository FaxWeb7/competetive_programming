# Задача на нахождение максимального онлайна на сайте (дано время входа и выхода каждого юзера)
def max_online(n, tin, tout):
    events = []
    for i in range(n):
        events.append((tin[i], 'in')) # приход человека
        events.append((tout[i], 'out')) # выход человека
    events.sort()

    max_online = 0
    online = 0
    for event in events:
        if event[1] == 'in':
            online += 1
        elif event[1] == 'out':
            online -= 1
        max_online = max(online, max_online)
    return max_online


# Задача на нахождение кол-ва времени, когда на сайте присутствовал минимум 1 человек
def visitors_time(n, tin, tout):
    events = []
    for i in range(n):
        events.append((tin[i], 'in'))
        events.append((tout[i], 'out'))
    events.sort()

    ans = 0
    online = 0
    for i in range(2*n):
        if online >= 1:
            ans += events[i][0] - events[i-1][0]
        if events[i][1] == 'in':
            online += 1
        elif events[i][1] == 'out':
            online -= 1
    return ans


# Задача на нахождения онлайн в те моментф, когда босс зашел на сайт
def boss_counters(n, tin, tout, m, tboss):
    events = []
    for i in range(n):
        events.append((tin[i], 'in'))
        events.append((tout[i], 'out'))
    for i in range(m):
        events.append((tboss[i], 'boss'))
    events.sort()

    ans = []
    online = 0 
    for event in events:
        if event[1] == 'in':
            online += 1
        elif event[1] == 'out':
            online -= 1
        else:
            ans.append(online)
    return ans


# Задача на два прохода. Необходимо определить, был ли такой момент времени, когда все парк.места были заняты
def is_parking_full(n, m, tin, tout, from_place, to_place):
    events = []
    for i in range(m):
        events.append((tin[i], 'arrive', from_place[i], to_place[i]))
        events.append((tout[i], 'leave', from_place[i], to_place[i]))
    events.sort()

    ocup_places = 0
    for event in events:
        if event[1] == 'arrive':
            ocup_places += (event[3] - event[2]) + 1
        if event[1] == 'leave':
            ocup_places -= (event[3] - event[2]) + 1
        if ocup_places >= n:
            return True
    return False
