#include <stdio.h>
#include <strings.h>

typedef struct {
    double midterm_avg;
    double max_score;
    double min_score;
    int fail_count;
    int num_got_a;
} results;

void examStat(double midterm1Score[30]) {
    results midterm1;
    midterm1.midterm_avg = 0;
    midterm1.max_score = 0;
    midterm1.min_score = 100;
    midterm1.fail_count = 0;
    midterm1.num_got_a = 0;

    for (int i = 0; i < 30; i++) {
        if (midterm1.max_score < midterm1Score[i]) {
            midterm1.max_score = midterm1Score[i];
        }
        if (midterm1.min_score > midterm1Score[i]) {
            midterm1.min_score = midterm1Score[i];
        }
        if (midterm1Score[i] < 60) {
            midterm1.fail_count++;
        }
        if (midterm1Score[i] >= 93) {
            midterm1.num_got_a++;
        }
        midterm1.midterm_avg += midterm1Score[i];
    }

    midterm1.midterm_avg /= 30;

    printf("The average score of the midterm is %.2lf\n", midterm1.midterm_avg);
    printf("The maximum score of the midterm is %.2lf\n", midterm1.max_score);
    printf("The minimum score of the midterm is %.2lf\n", midterm1.min_score);
    printf("The number of students who failed the midterm is %d\n", midterm1.fail_count);
    printf("The number of students who got an A is %d\n", midterm1.num_got_a);
}

int main() {

    double midterm1Score[30];

    for (int i = 0; i < 30; i++) {
        printf("Enter the score of student %d: ", i + 1);
        scanf("%lf", &midterm1Score[i]);
    }

    examStat(midterm1Score);

}