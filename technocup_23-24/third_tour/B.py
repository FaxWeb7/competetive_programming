def get_flight_time_departure_to_arrival(s_h, s_m, f_h, f_m):
    start_minutes = s_h * 60 + s_m
    finish_minutes = f_h * 60 + f_m
    if start_minutes > finish_minutes:
        finish_minutes += 24 * 60
    elapsed_time = finish_minutes - start_minutes
    hours = elapsed_time // 60
    minutes = elapsed_time % 60
    return hours, minutes

def get_flight_time_arrival_to_departure(s_h, s_m, f_h, f_m):
    start_minutes = s_h * 60 + s_m
    finish_minutes = f_h * 60 + f_m
    if start_minutes > finish_minutes:
        finish_minutes += 24 * 60
    elapsed_time = finish_minutes - start_minutes
    if elapsed_time > 12 * 60:
        finish_minutes -= 24 * 60
    elapsed_time = finish_minutes - start_minutes
    hours = elapsed_time // 60
    minutes = elapsed_time % 60
    return hours, minutes



s1_h, s1_m, f1_h, f1_m = map(int, input().split())
s2_h, s2_m, f2_h, f2_m = map(int, input().split())

res1 = get_flight_time_departure_to_arrival(s1_h, s1_m, f1_h, f1_m)
res2 = get_flight_time_arrival_to_departure(s2_h, s2_m, f2_h, f2_m)
a = 0
diff = abs(abs(((res1[0]*60)+res1[1])-(a*60))-abs(((res2[0]*60)+res2[1])+(a*60)))
while diff >= 60:
    a+=1
    diff = abs(abs(((res1[0]*60)+res1[1])-(a*60))-abs(((res2[0]*60)+res2[1])+(a*60)))


if s1_h > s2_h:
    print(res1[0]-a, res1[1])
    print(res2[0]+a, res2[1])
else:
    print(res1[0]+a, res1[1])
    print(res2[0]-a, res2[1])