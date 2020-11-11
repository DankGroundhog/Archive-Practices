prices = [7,1,5,3,6,4]
profit = 0

# Conditions
# i+1 existe
# profit > i and i > 0, buy
# i+1 < i and i = 0, initial buy
# i+1 >= i and i = 0, wait
# i+1 > i and profit < i+1, sell
# i+1 > i and profit > i+1, wait

for i in range(len(prices)):
    if(i+1 <= len(prices)):

        if(i+1 < i and i == 0):
            # We buy initially
            profit += prices[i]
        elif(profit > i):
            # We buy
            profit = prices[i] - profit
        elif(i+1 >= i):
            # We wait till next run
            continue
        elif(i+1 > i and profit > i+1):
            # We wait since next element yields
            # results.
            continue
        elif(i+1 > i and profit < i+1):
            # We sell
            profit += prices[i]
    print("Current profit on run {}: {}".format(i,profit))