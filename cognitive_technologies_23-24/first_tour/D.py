#wrong answer

from math import sqrt

r = int(input())
b = int(input())
a = int(input())

distance_to_lake = a + ((-sqrt(2)/2)*r)
distance_to_house = sqrt((b-(sqrt(2)/2)*r)**2 + ((-sqrt(2)/2)*r)**2)

print(distance_to_lake + distance_to_house)