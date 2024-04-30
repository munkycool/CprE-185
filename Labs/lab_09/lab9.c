// Lab 09 DS4Talker Skeleton Code       

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 0   // Set this to 0 to disable debug output

typedef struct {
	int x_axis;
	int y_axis;
} Axis;

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);
//Axis chose_word_animation(char* arg, int up, int left, int down, int right, int y_axis, int x_axis);
int draw_character(int y, int x, char use);

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
	int printword = 0;
	char userstring[4096];
	int wordlength = 0;
	char userSentence[4096] = "";
	int num, k = 0;
	int stringLengths[4096];	

	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++) {
			printf("%s,", wordlist[i]);

		}
		printf("\n");
	}

	// most of your code goes here. Do not forget to include the ncurses library 

	y_axis = 9;
	x_axis = 4;

	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	y_axis = 4;
	x_axis = -1;

	mvprintw(0,0, "Use the arrow keys to move the cursor and press enter to add a space and the word to the sentence.\n");
	mvprintw(1,0, "Press N to add the word to the sentence without a space. Press backspace to delete the last word.\n");
	mvprintw(2,0, "Press c to clear the sentence. Press C to capitalize the first letter of the next word.\n");
	mvprintw(1,125, "Press q to quit.\n");

	while(1) {
		//usleep(100);

		if (printword < 0) {
			printword = 0;
		}
		else if (printword > wordcount) {
			printword = wordcount;
		}

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

		int ch = getch();

		switch(ch) {
			case KEY_UP:
				y_axis -=4;
				mvprintw(y_axis + 4, x_axis, " ");
				printword -= 15;
				break;
			case KEY_DOWN:
				y_axis +=4;
				mvprintw(y_axis - 4, x_axis, " ");
				printword += 15;
				break;
			case KEY_LEFT:
				x_axis -=10;
				mvprintw(y_axis, x_axis + 10, " ");
				printword--;
				break;
			case KEY_RIGHT:
				x_axis +=10;
				mvprintw(y_axis, x_axis - 10, " ");
				printword++;
				break;
			default:
				break;
		}

		if (x_axis > 149) {
			x_axis = 149;
		}
		else if (x_axis < 9) {
			x_axis = 9;
		}
		else if (y_axis < 4) {
			y_axis = 4;
		}
		else if (y_axis > 24) {
			y_axis = 24;
		}
		else if (y_axis == 24 && x_axis > 9) {
			y_axis = 24;
			x_axis = 9;
		}

		// printing the words

		// enter key to add a space and the word to the userSentence
		// N key to add the word to the userSentence
		// backspace to delete the last word
		// c to clear the sentence
		// q to quit
		// C to capitalize the first letter of the next word

		if (ch == '\n') {
			// Check if there's enough space in userSentence for the new word and space
			if (strlen(userSentence) < 80) {
				strcpy(userstring, " ");
				strcat(userstring, wordlist[printword]);
				stringLengths[num] = strlen(userstring);
				strcat(userSentence, userstring);
				mvprintw(26, 5, "%s", userSentence);
				num++;
			}
		}

		if (ch == 'N') {
			// Check if there's enough space in userSentence for the new word and space
			if (strlen(userSentence) < 80) {
				strcpy(userstring, "");
				strcat(userstring, wordlist[printword]);
				stringLengths[num] = strlen(userstring);
				strcat(userSentence, userstring);
				mvprintw(26, 5, "%s", userSentence);
				num++;
			}
		}
		
		if (ch == '\x7f') {
			int length;
			length = strlen(userSentence);
			if (!(length == 0)) {
				for (k = length; k > length - stringLengths[num - 1]; k--) {
					userSentence[k] = ' ';
					mvprintw(26, k + 4, " ");
				}
				userSentence[k] = '\0';
				num--;
			}
		}

		if (ch == 'c') {
			for (int i = 0; i < strlen(userSentence); i++) {
				userSentence[i] = ' ';
				mvprintw(26, i + 5, " ");
			}
			userSentence[0] = '\0';
		}

		if (ch == 'C') {
			// Capitalize the first letter of the next word
			// Check if there's enough space in userSentence for the new word and space
			if (strlen(userSentence) < 80) {
				strcpy(userstring, " ");
				strcat(userstring, wordlist[printword]);
				stringLengths[num] = strlen(userstring);
				userstring[1] = toupper(userstring[1]);
				strcat(userSentence, userstring);
				mvprintw(26, 5, "%s", userSentence);
				num++;
			}
		}

		// Draw the * character after the words
		mvprintw(y_axis, x_axis, "*");

		if (ch == 'q') {
			break;
		}

		//mvprintw(0,0, "%d, %d", y_axis, x_axis);

		refresh();
	}

	endwin();

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

int draw_character(int y, int x, char use) {
	mvaddch(y, x, use);
	refresh();
	return 0;
}

/*
Axis chose_word_animation(char* arg, int up, int left, int down, int right, int y_axis, int x_axis) {
	char* wordlist[MAXWORDS];
	int wordcount;
	int i;
	wordcount = read_words(wordlist, arg);

	for (i = 0; i < wordcount; i++) {
		mvprintw(y_axis, x_axis, "*");
		refresh();
	}

	Axis newAxis;
	newAxis.x_axis = x_axis;
	newAxis.y_axis = y_axis;
	return newAxis;
}
*/
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
