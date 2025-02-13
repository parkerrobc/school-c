#include <pthread.h>
#include "homework-4.h"

/***
 * Global Properties
 */ 
float average;
int minimum;
int maximum;

/***
 * Struct to handle the params passed to the threads
 */ 
typedef struct {
    int *a;
    int size;
} parallel_params;

/***
 * Struct which makes function calls anonymous.
 * To add a function here it must be of type void * (void *)
 */ 
const static struct {
  void *(*func)(void *params);
} homework_4_functions[] = {
    {calculateAverage},
    {findMinimum},
    {findMaximum},
};

/***
 * Main function of homework 4. This triggers the threads.
 */ 
void homeworkFourParallelAnalysis(int *a, int size) {

    /***
     * Determine number of threads to create based on the number of thread functions we have defined.
     * In this case it will be 3
     */ 
    int NUM_THREADS = sizeof homework_4_functions / sizeof *homework_4_functions;

    printf("\n\n");
    printf("%s", HOMEWORK_FOUR_PARALLEL_ANALYSIS);
    printf("\n\n");

    /***
     * Initialize the threads that will be used
     */ 
    pthread_t workers[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        /***
         * Create the params to pass to the thread functions
         */ 
        parallel_params *args = malloc(sizeof *args);
        args->a = a;
        args->size = size;

        pthread_attr_t attr;
        pthread_attr_init(&attr);

        /***
         * Create the threads
         */ 
        pthread_create(&workers[i], &attr, homework_4_functions[i].func, args);
    }

    /***
     * Join the threads back with the main process
     */ 
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(workers[i], NULL);
    }

    /***
     * Print the results 
     */
    printf("\n\n");
    printf("The average value is: %.2f\n", average);
    printf("The minimum value is: %d\n", minimum);
    printf("The maximum value is: %d\n", maximum);
}

/***
 * Sum all the values in the array and divide by the size
 */ 
void *calculateAverage(void *params) {
    parallel_params *args = params;

    int *a = args->a;
    int size = args->size;

    for (int i = 0; i < size; i++) {
        average += (float) a[i];
    }

    average = (float) average / size;

    free(args);
    pthread_exit(0);
}

/***
 * Start with the first element in the array
 * and check if thats larger than the next element.
 * If so, the next element is the new minimum and repeat
 */ 
void *findMinimum(void *params) {
    parallel_params *args = params;

    int *a = args->a;
    int size = args->size;

    minimum = a[0];

    for (int i = 1; i < size; i++) {
        if (minimum > a[i]) {
            minimum = a[i];
        }
    }

    free(args);
    pthread_exit(0);
}

/***
 * Start with the first element in the array
 * and check if that is smaller than the next element.
 * If so, the next element is the new maximum and repeat
 */ 
void *findMaximum(void *params) {
    parallel_params *args = params;

    int *a = args->a;
    int size = args->size;

    maximum = a[0];

    for (int i = 1; i < size; i++) {
        if (maximum < a[i]) {
            maximum = a[i];
        }
    }

    free(args);
    pthread_exit(0);
}

