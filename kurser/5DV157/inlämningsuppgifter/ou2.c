/**
 * @file ou2.c
 * @author Lukas Ejvinsson (luej0002@student.umu.se)
 * @brief Takes in scores from a variable amount of judges, finds the lowest
 * and highest scores, and then computes the average excluding those two scores.
 *
 * For example, if 4 judges score the following:
 * {1, 3, 4, 3}\n
 * Then this code would compute the following:\n
 * Lowest judge score: 1\n
 * Highest judge score: 4\n
 * Final average score (will exclude 1 and 4): 6/2 = 3
 *
 * Program accepts scores as floating point numbers.
 * 
 * @param MIN_NUM_OF_JUDGES The minimum allowed number of judges to be entered by user.
 * @param MAX_NUM_OF_JUDGES The maximum allowed number of judges to be entered by user.
 * 
 * @version 2.0
 * @date 2024-10-21
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Sets precision of output values.
 * 
 */
#define OUTPUT_PRECISION 1

/**
 * @brief Prints the program information.
 * 
 */
void programInfo(void) {
	printf("Program information\n");
	printf("The program reads in the number of judges and the score from each judge.\n");
	printf("Then it calculates the average score without regard to the lowest and\n");
	printf("highest judge score. Finally it prints the results (the highest, the\n");
	printf("lowest and the final average score).\n\n");
}

/**
 * @brief Reads an integer using scanf.
 * 
 * @return Int from user.
 */
int readInt(void) {
	int n = 0;
	scanf("%d",&n);
	return n;

}

/**
 * @brief Reads a float using scanf.
 * 
 * @return Double from user.
 */
double readFloat(void) {
	double f = 0;
	scanf("%lf",&f);
	return f;

}

/**
 * @brief Read the number of judges from user using @ref readInt() and checks if it is within the allowed range.
 * 
 * @param[in] min Min allowed number of judges.
 * @param[in] max Max allowed number of judges.
 * @return The number of judges entered by user.
 */
int numOfJudges(int min, int max) {
	int n = 0;
	do {
		printf("Number of judges (min %d and max %d judges)? ", min, max);
		n = readInt();
	} while (n < min || n > max);
	return n;
}
	
/**
 * @brief Reads judge scores into an array using @ref readFloat().
 * 
 * @param[out] scores Destination array for scores.
 * @param[in] num_of_judges Number of judges.
 */
void readJudgeScores(double scores[], const int num_of_judges) {
	for(int i = 0; i < num_of_judges; i++) {
		printf("Score from judge %d? ", i+1);
		scores[i] = readFloat();
	}
}

/**
 * @brief Prints loaded scores from array.
 * 
 * @param[in] scores array of scores to print.
 * @param[in] num_of_judges Number of judges.
 */
void printLoadedScores(const double scores[], const int num_of_judges) {
	printf("Loaded scores:\n");
	for (int i = 0; i < num_of_judges; i++) {
		printf("Judge %d: %.1lf\n", i+1, scores[i]);
	}
}

/**
 * @brief Takes an array and finds the smallest value, the largest value,
 *  and the average excluding the largest and smallest values.
 * 
 * @param[in] v Input array.
 * @param[in] array_size Size of the input array.
 * @param[out] min The smallest value in the array.
 * @param[out] max The largest value in the array.
 * @param[out] average The average value of the array excluding @p min and @p max.
 */
void minMaxAverage(const double v[], const int array_size, double *min, double *max, double *average) {
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
	*average = (sum - (*max + *min))/(array_size - 2);
	
}

/**
 * @brief Prints the scores summary.
 * 
 * @param[in] min The lowest judge score.
 * @param[in] max The highest judge score.
 * @param[in] average The average judge score excluding @p min and @p max.
 */
void printSummary(double min, double max, double average) {
	printf("Final result:\n");
	printf("Highest judge score: %.*lf\n", OUTPUT_PRECISION, max);
	printf("Lowest judge score: %.*lf\n", OUTPUT_PRECISION, min);
	printf("Final average score: %.*lf\n", OUTPUT_PRECISION, average);
}

int main(int argc, char * argv[]) {

	int MIN_NUM_OF_JUDGES;
	int MAX_NUM_OF_JUDGES;

	if (argc == 3) {
		MIN_NUM_OF_JUDGES = atoi(argv[1]);
		MAX_NUM_OF_JUDGES = atoi(argv[2]);
	} else {
		MIN_NUM_OF_JUDGES = 3;
		MAX_NUM_OF_JUDGES = 10;
	}

	

	// Check to avoid divide by zero error. If found, exit the program.
	if (MIN_NUM_OF_JUDGES < 3) {
		printf("Internt konfigurationsfel: MIN_NUM_OF_JUDGES < 3.\n");
		return EXIT_FAILURE;
	}


	// Declare all main function variables
	double scores[MAX_NUM_OF_JUDGES];
	int num_of_judges = 0;
	double min, max, average = 0;

	// Set array to all zeroes
	memset(scores,0,sizeof(scores));

	programInfo();
	num_of_judges = numOfJudges(MIN_NUM_OF_JUDGES, MAX_NUM_OF_JUDGES);
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