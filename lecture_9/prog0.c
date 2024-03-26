# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main () {
  int randomNumber[10];
  int i;

  srand(time(NULL));

  for (i = 0; i < 10; i++) {
    randomNumber[i] = rand() % (500 - 100 + 1) + 100;
  }

 for (i = 0; i < 10; i++) {
    printf("%d\n", randomNumber[i]);
  }

  return 0;
}