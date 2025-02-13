#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***
 * Include homework here
 */
#include "homework/homework-2.c"
#include "homework/homework-4.c"

/***
 * User input functions
 */
void populateArrayFromInput(int *a, int size);
int continueMenu();
int printMenu();

/***
 * Function map to dynamically generate menu with available selections
 * example: User enters 1 in the menu, homeworkFourParallelAnalysis function is called
 * 
 * All functions are required to have the three parameters:
 * - int *a
 * - int size 
 * This is because the function call is anonymous and generic
 */ 
const static struct {
  const char *name;
  void (*func)(int *a, int size);
} function_map[] = {
    { HOMEWORK_TWO_PRINT_FORWARD,  homeworkTwoPrintForward},
    { HOMEWORK_TWO_PRINT_BACKWARD, homeworkTwoPrintBackward },
    { HOMEWORK_TWO_RECURSIVE_PRINT_FORWARD, homeworkTwoRecursivePrintForward },
    { HOMEWORK_TWO_RECURSIVE_PRINT_BACKWARD, homeworkTwoRecursivePrintBackward },
    { HOMEWORK_TWO_BUBBLE_SORT, homeworkTwoBubbleSort },
    { HOMEWORK_TWO_EFFICIENT_BUBBLE_SORT, homeworkTwoEfficientBubbleSort },
    { HOMEWORK_TWO_LINEAR_SEARCH, homeworkTwoLinearSearch },
    { HOMEWORK_TWO_BINARY_SEARCH, homeworkTwoBinarySearch },
    { HOMEWORK_TWO_RECURSIVE_LINEAR_SEARCH, homeworkTwoRecursiveLinearSearch },
    { HOMEWORK_TWO_RECURSIVE_BINARY_SEARCH, homeworkTwoRecursiveBinarySearch },
    { HOMEWORK_FOUR_PARALLEL_ANALYSIS, homeworkFourParallelAnalysis },
};
