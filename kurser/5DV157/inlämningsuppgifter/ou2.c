/* 
Lukas Ejvinsson
Teknisk Fysik F24
Umeå Universitet
TFY24LEN
luej0002@student.umu.se

Inlämningsuppgift 2
 */

#include <stdio.h>
#include <stdbool.h>

// Function to print the menu.
bool menu(void) {
	printf("Program information\n");
	printf("The program reads in the number of judges and the score from each judge.\n");
	printf("Then it calculates the average score without regard to the lowest and\n");
	printf("highest judge score. Finally it prints the results (the highest, the\n");
	printf("lowest and the final average score).\n\n");
	return true;
}

// Function to read integers.
int readInt(void) {
	int n;
	scanf("%d",&n);
	return n;

}

// Function to read floats.
double readFloat(void) {
	double f;
	scanf("%lf",&f);
	return f;

}

// Function to read the number of judges and check if it is within the allowed range.
bool numOfJudges(int *n, int min, int max) {
	printf("Number of judges (min %d and max %d judges)? ", min, max);
	*n = readInt();
	if (*n >= min && *n <= max) {
		return true;
	} else {
		return false;
	}
}

// Reads a judge score. Use in for loop in main.
bool judgeScore(double arr[], int i) {
	printf("Score from judge %d? ", i+1);
	arr[i] = readFloat();
	return true;
}

// Prints the loaded judge scores. Use in for loop in main.
bool printLoadedScore(double arr[], int i) {
	printf("Judge %d: %.1lf\n", i+1, arr[i]);
	return true;
}

// Returns the largest value in an array. Also returns the index of the largest number.
double maxFloat(double arr[],int size, int *p) {
	double max = arr[0];
	*p = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
			*p = i;
		}
			
	}
	return max;
}

// Returns the smallest value in an array. Also returns the index of the smallest number.
double minFloat(double arr[],int size, int *p) {
	double min = arr[0];
	*p = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
			*p = i;
		}
	}
	return min;
}

// Returns the average value of an array minus the smallest and largest values.
double averageFloat(double arr[], int size, int min, int max) {
	double average = 0;
	double sum = 0;
	int i = 0;
	for (i = 0; i < size; i++) {
		if (i != min && i != max) {
			sum += arr[i];
		}
	}
	average = sum/(i);
	return average;
}


int main(void) {

	// Number of judges.
	int judges;

	menu();

	while(!numOfJudges(&judges,3,10));

	double judge_scores[10];
	printf("\n");

	for (int i = 0; i < judges; judgeScore(judge_scores,i), i++);

	printf("\nLoaded scores:\n");
	
	for (int i = 0; i < judges; printLoadedScore(judge_scores,i), i++);

	int min; 
	int max;
	printf("\nFinal result:\n");
	printf("Highest judge score: %.1lf\n", maxFloat(judge_scores,judges, &max));
	printf("Lowest judge score: %.1lf\n",minFloat(judge_scores,judges, &min));
	printf("Final average score: %.1lf\n",averageFloat(judge_scores,judges, min, max));


	return 0;
}