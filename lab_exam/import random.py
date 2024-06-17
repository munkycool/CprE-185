import random
import time

# Rolling a dice 600 times and getting the mean of the results

def roll_dice():
    return random.randint(1, 6)

#print(roll_dice())

while True:
    random.seed(time.time())
    player2 = roll_dice() + roll_dice()

    luckyNumber = input("Player 1, enter your lucky number: ")
    luckyNumber = int(luckyNumber)  # convert the input to an integer

    random.seed(luckyNumber)
    player1 = roll_dice() + roll_dice()

    print("Player 1: ", player1)
    print("Player 2: ", player2)

    if player1 > player2:
        print("Player 1 wins!")
    elif player1 < player2:
        print("Player 2 wins!")
    elif player1 == player2:
        print("It's a tie! No winner today :P")
    elif luckyNumber == -99:
        exit()
    
# def main():
#     results = []
#     for i in range(10000):
#         for i in range(10):
#             results.append(roll_dice())
#             # calculate the mean of the 10 rolls
# #            mean = sum(results)/len(results)
# #            print("The mean is: ", mean)
    
#     # calculate the standard deviation
#     mean = sum(results)/len(results)
#     print("The mean is: ", mean)
#     variance = sum((x - mean) ** 2 for x in results) / len(results)
#     print("The standard deviation is: ", variance ** 0.5)
    
#     # calculate the z score of a mean of 6
#     z_score = (16.25 - mean) / (variance ** 0.5)
#     print("The z score is: ", z_score)
    
    
# if __name__ == "__main__":
#     main()

    



    