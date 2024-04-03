import random

# Rolling a dice 600 times and getting the mean of the results

def roll_dice():
    return random.randint(1, 6)

def main():
    results = []
    for i in range(100):
        results.append(roll_dice())
    print("The mean of the results is: ", sum(results)/len(results))
    
if __name__ == "__main__":
    main()

    