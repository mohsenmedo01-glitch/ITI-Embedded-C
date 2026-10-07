#include <stdio.h>
#include <stdlib.h>
int main()
{
    int randomNumber;
    int guess;

    randomNumber = rand() % 100 + 1;  // google assisted for Searching the library

    printf("Guess the number: ");
    scanf("%d", &guess);

    if (guess == randomNumber)
    {
        printf("Correct!\n");
    }
    else
    {
        printf("Wrong! The number was %d\n", randomNumber);
    }

    return 0;
}