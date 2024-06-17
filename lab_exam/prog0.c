// Included libraries, all of which probably do *something* (luckily this time I know that they all actually do)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to calculate the body fat percentage
int calculateBodyFatPercentage(double wieght, double height, int age, int gender) {
    int total = 0;
    // if gender is 0, then the person is female
    if (gender == 0) {
        // a really cool provided formula
        total = (1.39 * wieght/pow(height, 2)) + (0.16 * age) - 9;
    }
    // if the gender is 1, then the gender of the person is male
    else if (gender == 1) {
        // a really cool provided formula, but this time with extra numbers!
        total = (1.39 * wieght/pow(height, 2)) + (0.16 * age) - (10.34 * 1) - 9;
    }

    return total;
}

// Main function
int main() {
    // Variable declaration 
    double wieght, height;
    int age, gender;
    int bodyFatPercentage;

    // Getting the input from the user
    printf("Enter your age: ");
    scanf("%d", &age);
    // checking to see if the user is too young 
    if (age < 20) {
        printf("Hold on there young Padawan, you're a bit too young to reliably calculate your body fat percentage\n");
        exit(0);
    }
    printf("Enter your gender (1 for male, 0 for female): ");
    scanf("%d", &gender);
    printf("Enter your height: ");
    scanf("%lf", &height);
    printf("Enter your wieght: ");
    scanf("%lf", &wieght);

    // Calculating the body fat percentage
    bodyFatPercentage = calculateBodyFatPercentage(wieght, height, age, gender);

    // Printing the body fat percentage as a function of normality
    // (though entirely too many if statements)
    // 1 is calculating for male respondents
    if (gender == 1) {
        if (age >= 20 && age <= 39) {
            if (bodyFatPercentage <= 19) {
                printf("Your body fat percentage is normal\n");
            }
            else if (bodyFatPercentage > 19 && bodyFatPercentage <= 25) {
                printf("Your body fat percentage is above average\n");
            }
            else if (bodyFatPercentage > 25) {
                printf("Your body fat percentage is very high\n");
            }
        }
        if (age >= 40 && age <= 59) {
            if (bodyFatPercentage <= 22) {
                printf("Your body fat percentage is normal\n");
            }
            else if (bodyFatPercentage > 22 && bodyFatPercentage <= 28) {
                printf("Your body fat percentage is above average\n");
            }
            else if (bodyFatPercentage > 28) {
                printf("Your body fat percentage is very high\n");
            }
        }
        if (age >= 60 && age <= 79) {
            if (bodyFatPercentage <= 25) {
                printf("Your body fat percentage is normal\n");
            }
            else if (bodyFatPercentage > 25 && bodyFatPercentage <= 30) {
                printf("Your body fat percentage is above average\n");
            }
            else if (bodyFatPercentage > 30) {
                printf("Your body fat percentage is very high\n");
            }
        }
    }
    // calculating for female respondents 
    if (gender == 0) {
        if (age >= 20 && age <= 39) {
            if (bodyFatPercentage <= 33) {
                printf("Your body fat percentage is normal\n");
            }
            else if (bodyFatPercentage > 33 && bodyFatPercentage <= 39) {
                printf("Your body fat percentage is above average\n");
            }
            else if (bodyFatPercentage > 39) {
                printf("Your body fat percentage is very high\n");
            }
        }
        if (age >= 40 && age <= 59) {
            if (bodyFatPercentage <= 35) {
                printf("Your body fat percentage is normal\n");
            }
            else if (bodyFatPercentage > 35 && bodyFatPercentage <= 40) {
                printf("Your body fat percentage is above average\n");
            }
            else if (bodyFatPercentage > 40) {
                printf("Your body fat percentage is very high\n");
            }
        }
        if (age >= 60 && age <= 79) {
            if (bodyFatPercentage <= 36) {
                printf("Your body fat percentage is normal\n");
            }
            else if (bodyFatPercentage > 36 && bodyFatPercentage <= 42) {
                printf("Your body fat percentage is above average\n");
            }
            else if (bodyFatPercentage > 42) {
                printf("Your body fat percentage is very high\n");
            }
        }
    }

    // haha, can't get sued now bitch
    printf("THIS IS NOT A REPLACEMENT FOR PROFESSIONAL MEDICAL ADVICE, SEE A DOCTOR IF YOU HAVE HEALTH CONCERS\n");

}