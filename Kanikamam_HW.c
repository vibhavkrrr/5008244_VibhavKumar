#include <stdio.h>
int main() {
    int day;

    // Keep asking the user until they enter a valid number (1 to 7)
    while (1) {
        printf("Enter any day between 1 to 7: ");
        scanf("%d", &day);

        if (day >= 1 && day <= 7) {
            // Valid input, use switch-case to print the day
            switch(day) {
                case 1: printf("Monday\n"); break;
                case 2: printf("Tuesday\n"); break;
                case 3: printf("Wednesday\n"); break;
                case 4: printf("Thursday\n"); break;
                case 5: printf("Friday\n"); break;
                case 6: printf("Saturday\n"); break; // Fixed spelling
                case 7: printf("Sunday\n"); break;
            }
            break; // exit the loop after valid input
        } else {
            // Invalid input
            printf("Invalid number! Please enter a number between 1 and 7.\n\n");
        }
    }

    return 0;
}

