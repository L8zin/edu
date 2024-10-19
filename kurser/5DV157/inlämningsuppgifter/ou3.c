/*
 * Programmeringsteknik med C och Matlab
 * Fall 22
 * Assignment 3

 * File:         ou3.c
 * Description:  A simple implementation of Conway's Game of Life. Lets the user
 *               choose initial configuration. Then let them step or exit.
 *               Prints the game field in each step.
 * Author:
 * CS username:
 * Date:
 * Version:
 * Limitations:  No validation of input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Constants, representation of states */
#define ALIVE 'X'
#define DEAD '.'

#define BUFLEN 1024

#define ROWS 10
#define COLS 10

/* Declaration of data structure */
typedef struct cell {
	char current;
	char next;
} cell;

/* Function:    get_start_state
 * Description: Lets the user choose starting state
 * Input:       None.
 * Output:      The users choice. Should be one of the letters G, S,R or C.
 */
char get_start_state(void)
{
	int ch = 0;

	printf("Select world spec to load ([G]lider, [S]emaphore, [R]andom ");
	printf("or [C]ustom): ");

	ch = getchar();

	/* Eat any trailing newline */
	if (ch != '\n') {
		getchar();
	}
	return ch;
}

/* Function:    clear_world
 * Description: Initialize all the cells in the world to dead
 * Input:       rows - the number of rows in the world
 *              cols - the number of columns in the world
 *              world - the array representing the world
 * Output:      The world array is updated.
 */
void clear_world(const int rows, const int cols, cell world[rows][cols])
{
	for (int r = 0 ; r < rows ; r++) {
		for (int c = 0 ; c < cols ; c++) {
			world[r][c].current = DEAD;
		}
	}
}

/* Function:    load_glider
 * Description: Inserts a glider into the world.
 * Input:       rows - the number of rows in the world
 *              cols - the number of columns in the world
 *              world - the array representing the world
 * Output:      The world array is updated.
 */
void load_glider(const int rows, const int cols, cell world[rows][cols])
{
	world[0][1].current = ALIVE;
	world[1][2].current = ALIVE;
	world[2][0].current = ALIVE;
	world[2][1].current = ALIVE;
	world[2][2].current = ALIVE;
}

/* Function:    load_semaphore
 * Description: Inserts a semaphore into the world.
 * Input:       rows - the number of rows in the world
 *              cols - the number of columns in the world
 *              world - the array representing the world
 * Output:      The world array is updated.
 */
void load_semaphore(const int rows, const int cols, cell world[rows][cols])
{
	world[8][1].current = ALIVE;
	world[8][2].current = ALIVE;
	world[8][3].current = ALIVE;
}

/* Function:    load_random_state
 * Description: Inserts a random structure into the world.
 * Input:       rows - the number of rows in the world
 *              cols - the number of columns in the world
 *              world - the array representing the world
 * Output:      The world array is updated. There is a 50 % chance that a cell
 *              is alive.
 */
void load_random_state(const int rows, const int cols, cell world[rows][cols])
{

}

/* Function:    load_custom_state
 * Description: Lets the user specify a structure that then is inserted into
 *              the world.
 * Input:       rows - the number of rows in the world
 *              cols - the number of columns in the world
 *              world - the array representing the world
 * Output:      The world array is updated.
 */
void load_custom_state(const int rows, const int cols, cell world[rows][cols])
{
	char buf[BUFLEN];
	char *sc;
	int r, c;

	printf("Give custom format string (r1,c1; r2,c2; ...): ");

	// Read input into buffer
	fgets(buf,BUFLEN,stdin);
	// First pair to parse
	sc=buf;
	do {
		// Parse row, column pair
		if (sscanf(sc,"%d,%d;", &r, &c) == 2) {
			world[r][c].current = ALIVE;
		}
		// Advance semicolon pointer to next semi-colon
		sc=strchr(sc,';');
		if (sc) {
			// If we found a semi-colon, advance past it
			sc++;
		}
	} while (sc != NULL);
}

/* Function:    init_world
 * Description: Loads a structure that the user selects
 * Input:       rows - the number of rows in the world
 *              cols - the number of columns in the world
 *              world - the array representing the world
 * Output:      The world array is updated.
 */
void init_world(const int rows, const int cols, cell world[rows][cols])
{
	char choice;

	clear_world(rows,cols,world);

	choice=get_start_state();

	switch (choice) {
	case 'g':
	case 'G':
		load_glider(rows, cols, world);
		break;
	case 's':
	case 'S':
		load_semaphore(rows, cols, world);
		break;
	case 'r':
	case 'R':
		load_random_state(rows, cols, world);
		break;
	case 'c':
	case 'C':
	default:
		load_custom_state(rows, cols, world);
		break;
	}
}

void get_next_state(int x, int y, int rows, int cols, cell world[rows][cols]) {
   int neighbours = 0;
   if (world[x][y].current == ALIVE) {
        if(world[x-1][y-1].current == ALIVE) {
            neighbours++;
        }
        if(world[x-1][y].current == ALIVE) {
            neighbours++;
        }
         if(world[x-1][y+1].current == ALIVE) {
            neighbours++;
        }
         if(world[x][y-1].current == ALIVE) {
            neighbours++;
        }
         if(world[x][y+1].current == ALIVE) {
            neighbours++;
        }
         if(world[x+1][y-1].current == ALIVE) {
            neighbours++;
        }
         if(world[x+1][y].current == ALIVE) {
            neighbours++;
        }
         if(world[x+1][y+1].current == ALIVE) {
            neighbours++;
        }
        printf("cell %d,%d has %d neighbours.\n",x,y,neighbours);
        if (neighbours >)
   }
}
void load_next_frame(const int rows, const int cols, cell world[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            get_next_state(i,j,rows, cols, world);
        }
    }

}




/* Function:    main
 * Description: Start and run simulations, interact with the user.
 *              Lets the user choose initial structure and whether to step
 *              or exit. Writes information to the user, and the game world
 *              in each step.
 * Input:       None
 * Output:      Zero for normal exit, non-zero for error.
 */
int main(void) {   
    
    cell world[ROWS][COLS];
    clear_world(ROWS,COLS,world);
    init_world(ROWS,COLS,world);


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", world[i][j].current);
        }
        printf("\n");
    }

    load_next_frame(ROWS,COLS,world);


	return 0;
}
