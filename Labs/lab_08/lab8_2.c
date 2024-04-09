/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:
- Section:
-	NetID:
-	Date:
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159

/* 	Screen geometry
    Use ROWS and COLUMNS for the screen height and width (set by system)
    MAXIMUMS */
#define COLUMNS 100
#define ROWS 80

/* 	Character definitions taken from the ASCII table */
#define AVATAR L'0'
#define WALL '*'
#define EMPTY_SPACE ' '

/*	Number of samples taken to form an moving average for the gyroscope data
    Feel free to tweak this. */
#define NUM_SAMPLES 1


/*-----------------------------------------------------------------------------
-								Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);

/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void);

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, wchar_t use);

/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);

/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
/*	Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{

    setlocale(LC_ALL, "");

    int y, x;
    double gx, gy, gz;
    double fun_gx[NUM_SAMPLES];
    int loose;
    int exit_loop = 0;
    int exit_if = 0;

  if (argc != 2 )
  {
      printw("You must enter the difficulty level on the command line.");
      refresh();
      return;
  }
  else
  {
    /* 	Setup screen for Ncurses
        The initscr functionis used to setup the Ncurses environment
        The refreash function needs to be called to refresh the outputs
        to the screen */
    initscr();
    refresh();

    /* WEEK 2 Generate the Maze */

    /* Read gyroscope data and fill the buffer before continuing */

    /* Event loop */

    y = 0;
    x = 50;

    struct timeval last_action_time;
    gettimeofday(&last_action_time, NULL);

    generate_maze(atoi(argv[1]));
    draw_maze();
    draw_character(x, y, AVATAR);
    refresh();

    do
    {

    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    long elapsed_time = (current_time.tv_sec - last_action_time.tv_sec) * 1000L + 
                        (current_time.tv_usec - last_action_time.tv_usec) / 1000L;


    scanf("%lf, %lf, %lf", &gx, &gy, &gz); // Read gyroscope data



    if (elapsed_time >= 500) {
        /* Calculate the roll of the DS4 controller using the moving average */

        double roll = m_avg(fun_gx, NUM_SAMPLES, gx);

        roll = roll * -1;

        /* Update the avatar position based on the roll */

        if (MAZE[x][y+1] != WALL)
        {
            y++;
            gx = 0;
        }

        if (roll > .2 && x < COLUMNS - 1 && MAZE[x+1][y] != WALL)
        {
            x++;
            gx = 0;
        }
        else if (roll < .2 && x > 0 && MAZE[x-1][y] != WALL)
        {
            x--;
            gx = 0;
        }
/*
        if (MAZE[x][y+1] == WALL || MAZE[x+1][y] == WALL || MAZE[x-1][y] == WALL) {
            for (int i = 0; i < COLUMNS; i++)
            {
                if (MAZE[i][y+1] == WALL) {
                    for (int j = 0; j < 1; j++)
                    {
                        if (MAZE[i][j+1] == EMPTY_SPACE && MAZE[i][j] == EMPTY_SPACE) {
                            exit_if = 1;
                            break;
                        }
                }
                if (exit_if == 0) {
                    printf("YOU LOSE!\n");
                    loose = 1;
                    exit_loop = 1;
                    break;
                }
                else if (exit_if == 1) {
                    break;
                }
            }
            }
        }
*/

        if (MAZE[x+1][y] == WALL && MAZE[x-1][y] == WALL && MAZE[x][y+1] == WALL) {
            printf("YOU LOSE!\n");
            loose = 1;
            exit_loop = 1;
            break;
        }

        draw_maze();
        draw_character(x, y, AVATAR);
        refresh();

        last_action_time = current_time;

        //usleep(100000); // Sleep for 100ms

        /* Read data, update average */

        /* Is it time to move?  if so, then move avatar */

        // ending the maze

        if (y == ROWS - 1) {
            printf("YOU WIN!\n");
            loose = 0;
            exit_loop = 1;
            break;
        }
    }

    } while(exit_loop != 1); // Change this to end game at right time

    /* Print the win message */


    /* This function is used to cleanup the Ncurses environment.
    Without it, the characters printed to the screen will persist
    even after the progam terminates */
    endwin();

  }

    if (loose == 0) {
        printf("YOU WIN!\n");
    }
    else {
        printf("YOU LOSE!\n");
    }
}


double m_avg(double buffer[], int avg_size, double new_item)
{
    // Calculating the moving average of the buffer
    double sum = 0.0;
    int i = 0;

    // Shift the buffer to the left
    
    for (i = 0; i < avg_size - 1; i++)
    {
        buffer[i] = buffer[i + 1];
    }

    buffer[avg_size -1] = new_item;

    for(i = 0; i < avg_size; i++)
    {
        sum += buffer[i];
    }

    // Return the average

    return sum / (avg_size + 1);
}


/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y
    THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
    DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, wchar_t use)
{
    mvaddch(y,x,use);
    refresh();
}

double calc_roll(double x_mag) {
	if (x_mag < -1) {
		x_mag = -1;
	}
	if (x_mag > 1) {
		x_mag = 1;
	}
	return asin(x_mag) * -1.0;
}

double calc_pitch(double y_mag) {
    if (y_mag < -1) {
        y_mag = -1;
    }
    if (y_mag > 1) {
        y_mag = 1;
    }
    return asin(y_mag) * -1.0;
}

void generate_maze(int difficulty)
{
    srand(time(NULL));
    for (int i = 0; i < COLUMNS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            if (rand() % 100 < difficulty)
            {
                MAZE[i][j] = WALL;
            }
            else
            {
                MAZE[i][j] = EMPTY_SPACE;
            }
        }
    }
}

void draw_maze(void)
{
    for (int i = 0; i < COLUMNS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            mvaddch(j, i, MAZE[i][j]);
        }
    }
}