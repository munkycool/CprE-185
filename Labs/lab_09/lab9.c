// Lab 09 DS4Talker Skeleton Code       

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 0   // Set this to 0 to disable debug output

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);
int chose_word_animation(char* arg, int up, int down, int left, int right, int y_axis, int x_axis);
// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordcount;
	int i;
	int circle, x, square, triangle, up, left, down, right;
	wordcount = read_words(wordlist, argv[1]);
	int y_axis, x_axis;
	int collums[5];
	int rows[10];

	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++) {
			printf("%s,", wordlist[i]);

		}
		printf("\n");
	}

	// most of your code goes here. Do not forget to include the ncurses library 

	while(1) {

		scanf("%d, %d, %d, %d, %d, %d, %d, %d", &triangle, &circle, &x, &square, &up, &left, &down, &right);
		//initialize the screen
		initscr();

		i = 0;

		for (int j = 1; j < 7; j++) {
			for (int k = 1; k < 16; k++) {
				mvprintw(j*4, k*10, "%s", wordlist[i]);
				i++;
				if (i == wordcount) {
					break;
				}
			}
		}
		
		if (circle == 1) {
			exit(0);
		}
		
		chose_word_animation(argv[1], up, down, left, right, y_axis, x_axis);
		refresh();

	}



	return 0;
}

// DO NOT MODIFY THIS FUNCTION!
void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}

int chose_word_animation(char* arg, int up, int down, int left, int right, int y_axis, int x_axis) {
	char* wordlist[MAXWORDS];
	int wordcount;
	int i;
	wordcount = read_words(wordlist, arg);

	if (down == 1) {
		x_axis += 9;
	}

	if (up == 1) {
		x_axis -= 9;
	}
	if (right == 1) {
		y_axis += 4;
	}
	if (left == 1) {
		y_axis -= 4;
	}

	for (i = 0; i < wordcount; i++) {
		mvprintw(y_axis, x_axis, "*");
		refresh();
	}
}

// DO NOT MODIFY THIS FUNCTION!
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}
