/* 
Name: Lukas Ejvinsson
CS Username: TFY24LEN
Email: luej0002@student.umu.se
Date: 2024-10-15
Program Version: 1.0

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


// Defines the size of the array as well as the allowed amount of judges
#define MAX_NUM_OF_JUDGES 10
#define MIN_NUM_OF_JUDGES 3

//Sets how many decimals to output.
#define OUTPUT_PRECISION 1

// Prints the program info.
void programInfo(void) {
	printf("Program information\n");
	printf("The program reads in the number of judges and the score from each judge.\n");
	printf("Then it calculates the average score without regard to the lowest and\n");
	printf("highest judge score. Finally it prints the results (the highest, the\n");
	printf("lowest and the final average score).\n\n");
}

// Reads an integer from user.
int readInt(void) {
	int n;
	scanf("%d",&n);
	return n;

}

// Reads a float point number from user.
double readFloat(void) {
	double f;
	scanf("%lf",&f);
	return f;

}

// Clears a double array.
void clearDoubleArray(double v[], int array_size) {
	for (int i = 0; i < array_size; i++) {
		v[i] = 0;
	}
}

// Reads the number of judges from user and checks if it is within the allowed range.
int numOfJudges(void) {
	int n = 0;
	do {
		printf("Number of judges (min %d and max %d judges)? ", MIN_NUM_OF_JUDGES, MAX_NUM_OF_JUDGES);
		n = readInt();
	} while (n < MIN_NUM_OF_JUDGES || n > MAX_NUM_OF_JUDGES);
	return n;
}
	
// Reads judge scores into an array.
void readJudgeScores(double scores[], int num_of_judges) {
	for(int i = 0; i < num_of_judges; i++) {
		printf("Score from judge %d? ", i+1);
		scores[i] = readFloat();
	}
}

// Prints judge scores from an array.
void printLoadedScores(double scores[], int num_of_judges) {
	printf("Loaded scores:\n");
	for (int i = 0; i < num_of_judges; i++) {
	printf("Judge %d: %.1lf\n", i+1, scores[i]);
	}
}

// Finds the smallest and largest values in an array and then computes the
// arithmetic mean excluding those values.
// Outputs the min, max, and average through pointer arguments.
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
	*average = (sum - (*max + *min))/(array_size-2);
	
}

// Prints the score summary.
void printSummary(double min, double max, double average) {
	printf("Final result:\n");
	printf("Highest judge score: %.*lf\n", OUTPUT_PRECISION, max);
	printf("Lowest judge score: %.*lf\n", OUTPUT_PRECISION, min);
	printf("Final average score: %.*lf\n", OUTPUT_PRECISION, average);
}

int main(void) {

	double scores[MAX_NUM_OF_JUDGES];
	int num_of_judges = 0;
	double min, max, average = 0;

	// Initialize the array.
	clearDoubleArray(scores, sizeof(scores)/sizeof(scores[0]));

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
	return 0;
}