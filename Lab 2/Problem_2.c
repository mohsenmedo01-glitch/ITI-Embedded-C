#include<stdio.h>
int main() {
    int factorial = 1;
    int x;
    printf("Enter an positive integer: ");
    scanf("%d", &x);
    if (x<0){
        printf("Please enter a positive integer\n");
    }
    else{
        while (x>0){
            factorial =factorial * x;
            x--;
        }
        printf("The factorial is: %d\n", factorial);
    }
}