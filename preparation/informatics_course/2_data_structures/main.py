balance = 4000000
ton_coins = 20900289475583
percentage = balance/ton_coins

coins = [
    ["btc", 20000000, 47000],
    ["xrp", 100000000000, 0.5217],
    ["ada", 45000000000, 0.5388],
    ["ltc", 84000000, 70.60],
    ["matic", 10000000000, 0.842],
    ["avax", 720000000, 37.35],
    ["sand", 3000000000, 0.4634]
]

for coin in coins:
    print(coin[0],": $", int(coin[1]*percentage*coin[2]), sep="")