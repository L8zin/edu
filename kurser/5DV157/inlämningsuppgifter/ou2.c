/* 
Name: Lukas Ejvinsson
CS Username: TFY24LEN
Email: luej0002@student.umu.se
Date: 2024-10-15
Program Version: 1.1

Program Description:

Takes in scores from a variable amount of judges, finds the lowest
and highest scores, and then computes the average excluding those two scores.

For example, if 4 judges score the follwing:
{1, 3, 4, 3}
Then this code would compute the following:
Lowest judge score: 1
Highest judge score: 4
Final average score (will exclude 1 and 4): 6/2 = 3

Program accepts scores as floating point numbers.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// Define the size of the array as well as the allowed amount of judges.
// There must be a minimum of 3 judges to avoid division by zero.
#define MAX_NUM_OF_JUDGES 10
#define MIN_NUM_OF_JUDGES 3

//Set how many decimals to output.
#define OUTPUT_PRECISION 1

// Print the program info.
void programInfo(void) {
	printf("Program information\n");
	printf("The program reads in the number of judges and the score from each judge.\n");
	printf("Then it calculates the average score without regard to the lowest and\n");
	printf("highest judge score. Finally it prints the results (the highest, the\n");
	printf("lowest and the final average score).\n\n");
}

// Read an integer from user.
int readInt(void) {
	int n = 0;
	scanf("%d",&n);
	return n;

}

// Read a float point number from user.
double readFloat(void) {
	double f = 0;
	scanf("%lf",&f);
	return f;

}

// Clear a double array.
void clearDoubleArray(double v[], int array_size) {
	for (int i = 0; i < array_size; i++) {
		v[i] = 0;
	}
}

// Read the number of judges from user and checks if it is within the allowed range.
int numOfJudges(void) {
	int n = 0;
	do {
		printf("Number of judges (min %d and max %d judges)? ", MIN_NUM_OF_JUDGES, MAX_NUM_OF_JUDGES);
		n = readInt();
	} while (n < MIN_NUM_OF_JUDGES || n > MAX_NUM_OF_JUDGES);
	return n;
}
	
// Read judge scores into an array.
void readJudgeScores(double scores[], int num_of_judges) {
	for(int i = 0; i < num_of_judges; i++) {
		printf("Score from judge %d? ", i+1);
		scores[i] = readFloat();
	}
}

// Print judge scores from an array.
void printLoadedScores(double scores[], int num_of_judges) {
	printf("Loaded scores:\n");
	for (int i = 0; i < num_of_judges; i++) {
		printf("Judge %d: %.1lf\n", i+1, scores[i]);
	}
}

// Find the smallest and largest values in an array and then compute the
// arithmetic mean excluding those values.
// Output the min, max, and average through pointer arguments.
void minMaxAverage(double v[], int array_size, double *min, double *max, double *average) {
	*min = v[0];
	*max = v[0];
	double sum = v[0];
	
	for (int i = 1; i < array_size; i++) {
		
		if (v[i] < *min) {
			*min = v[i];
		} else if (v[i] > *max) {
			*max = v[i];
		}
		
		sum += v[i];
	}
	// Compute average excluding the min and max.
	*average = (sum - (*max + *min))/(array_size-2);
	
}

// Print the score summary.
void printSummary(double min, double max, double average) {
	printf("Final result:\n");
	printf("Highest judge score: %.*lf\n", OUTPUT_PRECISION, max);
	printf("Lowest judge score: %.*lf\n", OUTPUT_PRECISION, min);
	printf("Final average score: %.*lf\n", OUTPUT_PRECISION, average);
}

int main(void) {

	// Check to avoid divide by zero error. If found, exit the program.
	if (MIN_NUM_OF_JUDGES < 3) {
		printf("Program might result in division by zero, adjust MIN_NUM_OF_JUDGES to be >=3\n");
		return EXIT_FAILURE;
	}

	// Declare all main function variables
	double scores[MAX_NUM_OF_JUDGES];
	int num_of_judges = 0;
	double min, max, average = 0;

	// Initialize the array.
	clearDoubleArray(scores, MAX_NUM_OF_JUDGES);

	programInfo();
	num_of_judges = numOfJudges();
	printf("\n");

	readJudgeScores(scores,num_of_judges);
	printf("\n");
	printLoadedScores(scores,num_of_judges);

	minMaxAverage(scores,num_of_judges,&min,&max,&average);
	printf("\n");
	printSummary(min,max,average);

	printf("Normal exit.\n");
	return EXIT_SUCCESS;
}