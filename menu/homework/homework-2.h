/***
* homework-2
*/
void homeworkTwoPrintForward(int *a, int size)
void homeworkTwoPrintBackward(int *a, int size)
void homeworkTwoRecursivePrintForward(int *a, int size)
void homeworkTwoRecursivePrintBackward(int *a, int size)
void homeworkTwoBubbleSort(int *a, int size)
void homeworkTwoEfficientBubbleSort(int *a, int size)
void homeworkTwoLinearSearch(int *a, int size)
void homeworkTwoBinarySearch(int *a, int size)
void homeworkTwoRecursiveLinearSearch(int *a, int size)
void homeworkTwoRecursiveBinarySearch(int *a, int size)

/***
* private functions used by homework-2
*/
void recursivePrintForward(int *a, int size, int index)
void recursivePrintBackward(int *a, int size, int index)
int runRecursiveLinearSearch(int target, int *a, int size, int index);
int runRecursiveBinarySearch(int target, int *a, int size, int high, int low);
void swap(int *x, int *y);

/***
 * Pretty printed versions of the functions
 */
char HOMEWORK_TWO_PRINT_FORWARD[30] = "Homework 2: Print Forward";
char HOMEWORK_TWO_PRINT_BACKWARD[30] = "Homework 2: Print Backward";
char HOMEWORK_TWO_RECURSIVE_PRINT_FORWARD[45] = "Homework 2: Print Forward: Recursive";
char HOMEWORK_TWO_RECURSIVE_PRINT_BACKWARD[45] = "Homework 2: Print Backward: Recursive";
char HOMEWORK_TWO_BUBBLE_SORT[30] = "Homework 2: Bubble Sort";
char HOMEWORK_TWO_EFFICIENT_BUBBLE_SORT[45] = "Homework 2: Bubble Sort: Efficient";
char HOMEWORK_TWO_LINEAR_SEARCH[30] = "Homework 2: Linear Search";
char HOMEWORK_TWO_BINARY_SEARCH[30] = "Homework 2: Binary Search";
char HOMEWORK_TWO_RECURSIVE_LINEAR_SEARCH[45] = "Homework 2: Linear Search: Recursive";
char HOMEWORK_TWO_RECURSIVE_BINARY_SEARCH[45] = "Homework 2: Binary Search: Recursive";