#include <stdio.h>

int main() {
    int i;
    int j;
    int sum;

    // Prompt the user to enter the first number
    printf("Enter the first number:\n");
    scanf("%d", &i);

    // Prompt the user to enter the second number
    printf("Enter the second number:\n");
    scanf("%d", &j);

    // Calculate the sum of the two numbers
    sum = i + j;

    // Display the result
    printf("The sum is: %d\n", sum);

    return 0;
}
