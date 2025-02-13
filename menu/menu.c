#include "menu.h"

/***
 * Main function that displays cli interface.
 * Application currently accepts integers as input; though not explicitly so.
 * (alpha input does not work and causes the application to crash)
 * (no safe guards exist)
 */
int main(int argc, char *argv[]) {
    int show_menu = 1;

    while (show_menu == 1) {
        int menuSelection = printMenu();

        if (menuSelection == -1) {
            printf("\n\nUKNOWN SELECTION\n\n");
            show_menu = continueMenu();
            continue;
        }

        printf("\n\nYou have choosen %s", function_map[menuSelection].name);
        printf("\nLet's begin!!");

        printf("\n\nHow many numbers do you want to enter into your array?");
        printf("\n(Enter number of elements in your arrary): ");

        int *a;
        int size;

        scanf("%d", &size);

	    a = (int*)calloc(size, sizeof(int));
        populateArrayFromInput(a, size);

        printf("\n\nLets run that function!\n\n");

        function_map[menuSelection].func(a, size);

        show_menu = continueMenu();
    }

    return 0;
}

int continueMenu() {
    printf("\n\nDo you want to start again?");
    printf("\n(1 for yes, 2 for no): ");

    int answer;

    scanf("%d", &answer);

    if (answer != 1) {
        printf("\nYou didn't answer yes, so we're assuming you want to stop");
        printf("\nThanks for playing!\n\n");
        return 0;
    } 

    system("cls");
    system("clear");

    return 1;
}

int printMenu() {

    printf("\nWhat array function would you like to run?\n");

    int size = sizeof(function_map) / sizeof(function_map[0]);

    for (int i = 0; i < size; i++) {
        int index = i + 1;
        printf("\n%d -- %s", index, function_map[i].name);
    }

    printf("\n\n(Enter number to run that function): ");

    int selection;

    scanf("%d", &selection);

    if (selection > 0 && selection <= size)
        return selection - 1;
    else {
        return -1;
    }
}

void populateArrayFromInput(int *a, int size) {
	printf("\nPlease enter %d numbers: ", size);

	for (int i = 0; i < size; i++)
		scanf("%d", &a[i]);

	printf("\nThank you!");

}
