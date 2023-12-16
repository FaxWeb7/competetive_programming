from sys import stdin, stdout, exit
n, m = list(map(int, stdin.readline().rstrip().split()))
t = list(map(int, stdin.readline().rstrip().split()))

ans = -1
for timezone in range(m):
    leftd = (t[0]-timezone)//m
    rightd = (t[n-1]-timezone)//m
    hour_in_day = True
    for day in range(leftd, rightd+1):
        day_hours = list(range((day*m)+timezone, ((day+1)*m)+timezone))
        if not any(el in day_hours for el in t):
            hour_in_day = False
            break
    if hour_in_day:
        ans = timezone
        break

stdout.write(str(ans))

# def check_tz(tz):
#     leftd = (t[0]-tz)//m
#     rightd = (t[n-1]-tz)//m
#     hour_in_day = True
#     for day in range(leftd, rightd+1):
#         day_hours = list(range((day*m)+tz, ((day+1)*m)+tz))
#         if not any(el in day_hours for el in t):
#             hour_in_day = False
#             break
#     if hour_in_day:
#         return True
#     return False
# ans = -1
# l_tz = 0
# r_tz = m-1
# while l_tz != r_tz:
#     m_tz = (l_tz + r_tz) // 2
#     if check_tz(m_tz):
#         r = m_tz
#         print('asd')
#         ans = m_tz + 1
#     else:
#         print('a')
#         l_tz = m_tz + 1
# stdout.write(str(ans))