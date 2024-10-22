/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/* Constants, representation of states */
#define ALIVE 'X'
#define DEAD '.'

#define BUFLEN 1024

#define ROWS 20
#define COLS 20

#define loopthrough(rows,both) for(int r = 0; r < ROWS; r++){for (int c = 0; c < COLS; c++){both}rows}

/* Declaration of data structure */
typedef struct cell {
	char current;
	char next;
} cell;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

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
	loopthrough(,world[r][c].current = (rand()%2) ? ALIVE : DEAD;)
	
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

int get_neighbours(int row, int col, int rows, int cols, cell world[rows][cols]) {
	int neighbours = 0;
	for (int r = max(0,row-1); r <= min(rows-1,row+1); r++) {
		for (int c = max(0,col-1); c <= min(cols-1,col+1); c++) {
			if (world[r][c].current == ALIVE && !(r == row && c == col)) {
				neighbours++;
			}
		}
	}
	return neighbours;
}

void set_next_state(int row, int col, int rows, int cols, cell world[rows][cols]) {
	char *next = &world[row][col].next;
	bool is_alive = world[row][col].current == ALIVE;
	int n = get_neighbours(row,col,rows,cols,world);
	if((!is_alive && n == 3) || (is_alive && (n == 2 || n == 3 ))) {
		*next = ALIVE;
	} else {
		*next = DEAD;
	}
}

void load_next_frame(const int rows, const int cols, cell world[rows][cols]) {
	loopthrough(,set_next_state(r,c,rows,cols,world);)
	loopthrough(,world[r][c].current = world[r][c].next;)
}

void print_frame(int rows, int cols, cell world[rows][cols]) {
	loopthrough(printf("\n");,printf("%c ", world[r][c].current);)
}

char menu(void) {
	printf("Select one of the following options:\n");
	printf("(enter) Step\n");
	printf("(any) Exit\n");

	char ch = getchar();
	return ch;
	
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
	srand(time(NULL));

    cell world[ROWS][COLS];
	const int rows = ROWS;
	const int cols = COLS;

	clear_world(rows,cols,world);

    init_world(rows,cols,world);

	char ch = 0;
	do {
		//system("clear");
		print_frame(rows,cols,world);
		ch = menu();
		
		load_next_frame(rows,cols,world);
	} while (ch == 10);
} 