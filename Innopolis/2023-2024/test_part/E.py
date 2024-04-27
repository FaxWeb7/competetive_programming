# def get_min_time(x, y, w, s):
#     if x == 0 or y == 0:
#         return max(abs(x), abs(y)) * w
#     else:
#         option_1 = min(abs(x), abs(y)) * s + abs(abs(x) - abs(y)) * w
#         option_2 = (abs(x) + abs(y)) * w
#         time = option_1 if option_1 < option_2  else option_2
#     return time

# x, y, w, s = list(map(int, input().split()))
# print(get_min_time(x, y, w, s))

# def res(x, y, w, s):
#     min_xy = min(x, y)
#     dig = min(s, 2*w) * min_xy
#     straight = w * (max(x,y)-min_xy)
#     if s < w:
#         if straight//w % 2 == 0:
#             straight = s*(max(x,y)-min_xy)
#         else:
#             straight = s*(max(x,y)-min_xy-1) + w
#     r = dig+straight
#     return r
# print(res(*map(int, input().split())))