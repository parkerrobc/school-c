#include <stdio.h>
#include "homework-2.h"

/***
* homework-2
*/
void homeworkTwoPrintForward(int *a, int size, int index) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
}

void homeworkTwoPrintBackward(int *a, int size, int index) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
}

void homeworkTwoRecursivePrintForward(int *a, int size) {
    recursivePrintForward(a, size, 0)
}

void homeworkTwoRecursivePrintBackward(int *a, int size) {
    recursivePrintBackward(a, size, 0)
}

void homeworkTwoBubbleSort(int *a, int size) {
    int complexity = 0;

    for (int j = 0; j < size - 1; j++)
        for (int i = 0; i < size - 1; i++) {
            complexity++;
            if (a[i] > a[i + 1])
                swap(&a[i], &a[i + 1]);
        }

    printf("\nComplexity: %d\n", complexity);
    homeworkTwoPrintForward(a, size);
}

void homeworkTwoEfficientBubbleSort(int *a, int size) {
    int complexity = 0;

	for (int j = 0; j < size - 1; j++) {
        int swapped = 0;

        for (int i = 0; i < size - j - 1; i++) {
            complexity++;
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }

    printf("\nComplexity: %d\n", complexity);
    homeworkTwoPrintForward(a, size);
}

void homeworkTwoLinearSearch(int *a, int size) {
	int target, i;
	int found = 0;
    int complexity = 0;

    printf("What number do you want to search for? ");
	scanf("%d", &target);

	for (i = 0; i < size && found != 1; i++) {
        complexity++;
        if (a[i] == target)
			found = 1;
    }

	if (found == 1)
		printf("\nWe found the number!\n");
	else
		printf("\nWe did not find the number :(\n");

    printf("\nComplexity: %d\n", complexity);
}

void homeworkTwoBinarySearch(int *a, int size) {
	int target, i;
	int found = 0;
	int low, high, middle;
    int complexity = 0;

    printf("Lets sort that array before starting...\n");
    efficientBubbleSort(a, size);

    low = 0;
	high = size - 1;

	printf("\n\nWhat number do you want to search for? ");
	scanf("%d", &target);

	while (low <= high) {
        complexity++;

        middle = (high + low )/2;

        if (a[middle] < target)
            low = middle + 1;
        else if (a[middle] == target) {
            found = 1;
            break;
        } else
            high = middle - 1;

    }

	if (found == 1)
		printf("\nWe found the number at index %d!\n", middle);
	else
		printf("\nWe did not find the number :(\n");


     printf("\nComplexity: %d\n", complexity);
}

void homeworkTwoRecursiveLinearSearch(int *a, int size) {
	int target, i;
	int found = 0;

    printf("What number do you want to search for? ");
	scanf("%d", &target);

    found = runRecursiveLinearSearch(target, a, size, 0);

    if (found == 1)
		printf("\nWe found the number!\n");
	else
		printf("\nWe did not find the number :(\n");

}

void homeworkTwoRecursiveBinarySearch(int *a, int size) {
	int target, i;
	int found = 0;
	int low, high, middle;

	low = 0;
	high = size - 1;

    printf("Lets sort that array before starting...\n");
    efficientBubbleSort(a, size);

	printf("\n\nWhat number do you want to search for? ");
	scanf("%d", &target);

    found = runRecursiveBinarySearch(target, a, size, high, low);

    if (found >= 0)
		printf("\nWe found the number at index %d!\n", found);
	else
		printf("\nWe did not find the number :(\n");

}


/***
* private functions used by homework-2
*/
void recursivePrintForward(int *a, int size, int index) {
	if (index == size - 1)
		printf("%d\n", a[index]);
	else {
		printf("%d ", a[index]);
		recursivePrintForward(a, size, index + 1);
	}
}

void recursivePrintBackward(int *a, int size, int index) {
	if (index == size - 1)
		printf("%d ", a[index]);
    else {
		recursivePrintBackward(a, size, index + 1);
		printf("%d ", a[index]);
	}
}

int runRecursiveLinearSearch(int target, int *a, int size, int index) {
    if (index == size) {
        return 0;
    }

    if (a[index] == target) {
        return 1;
    } else {
        return runRecursiveLinearSearch(target, a, size, index + 1);
    }
}

int runRecursiveBinarySearch(int target, int *a, int size, int high, int low) {
    if (high >= low) {
        int middle = (high + low) / 2;
        if (target == a[middle]) {
            return middle;
        } else {
            if (target < a[middle])
                return runRecursiveBinarySearch(target, a, size, middle - 1, low);
            else
                return runRecursiveBinarySearch(target, a, size, high, middle + 1);
        }
    } else {
        return -1;
    }
}

void swap(int *x, int *y) {
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
