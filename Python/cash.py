from cs50 import get_float


while True:
    cash = get_float("Change: ")
    if cash > 0 and cash <= 1000:
        break

cash *= 100
quaters = 25
dimes = 10
nickles = 5
pennies = 1
coins = 0

while True:
    if cash >= quaters:
        cash -= quaters
    elif cash >= dimes:
        cash -= dimes
    elif cash >= nickles:
        cash -= nickles
    elif cash >= pennies:
        cash -= pennies
    else:
        break
    coins += 1

result = round(coins / 100, 2)
result *= 100
print(int(result))
