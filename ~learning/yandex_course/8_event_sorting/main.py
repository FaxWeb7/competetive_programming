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
        events.append((tin[i], 'arrive', to_place[i] - from_place[i] + 1))
        events.append((tout[i], 'leave', to_place[i] - from_place[i] + 1))
    events.sort()

    ocup_places = 0
    for event in events:
        if event[1] == 'leave':
            ocup_places -= event[2]
        if event[1] == 'arrive':
            ocup_places += event[2]
        if ocup_places == n:
            return True
    return False


# Задача на нахождение минимального кол-ва машин на парковке в тот момент, когда парковка полностью забита
def min_cars_full_parking(n, m, tin, tout, from_place, to_place):
    events = []
    for i in range(m):
        events.append((tin[i], 'arrive', to_place[i] - from_place[i] + 1))
        events.append((tout[i], 'leave', to_place[i] - from_place[i] + 1))
    events.sort()

    now_cars = 0
    min_cars = m + 1
    ocup_places = 0
    for event in events:
        if event[1] == 'leave':
            ocup_places -= event[2]
            now_cars -= 1
        if event[1] == 'arrive':
            ocup_places += event[2]
            now_cars += 1
        if ocup_places == n:
            min_cars = min(min_cars, now_cars)
    return min_cars


# Задача на нахождение номеров машин на парковке в тот момент, когда парковка полностью забита
def car_numbers_full_parking(n, m, tin, tout, from_place, to_place):
    events = []
    for i in range(m):
        events.append((tin[0], 'arrive', to_place[i] - from_place[i] + 1))
        events.append((tout[0], 'leave', to_place[i] - from_place[i] + 1))
    unsorted_events = events
    events.sort()

    cars_numbers = []
    min_cars = m+1
    now_cars = 0
    ocup_places = 0
    for i in range(2*m):
        if events[i][1] == 'leave':
            ocup_places -= 1
            now_cars -= events[i][2]
            cars_numbers.remove(unsorted_events.index(events[i]) + 1)
        if events[i][1] == 'arrive':
            ocup_places += 1
            now_cars += events[i][2]
            cars_numbers.append(unsorted_events.index(events[i]) + 1)
        if ocup_places == n:
            min_cars = min(min_cars, now_cars)
    return (min_cars, cars_numbers)


    