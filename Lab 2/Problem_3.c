#include<stdio.h>
int main() {
    int x;
    printf("Enter an positive integer: ");
    scanf("%d", &x);
    if (x<0){
        printf("Please enter a positive integer\n");
    }
    else{
        for (int i=1;i<=10;i++){
            int multiplication = x*i;
            printf("The multiplication of %d * %d is: %d\n", x, i, multiplication);
        }
        
    }return 0;
}