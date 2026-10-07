#include<stdio.h>
int main() {
    char x;
    printf("Enter a character: ");
    scanf("%c", &x);
    if (x >='a' && x <='z'){
        switch (x){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            printf("%c is a vowel.\n", x);
            break;
        default:
            printf("%c is a consonant.\n", x);

        }

    }else {
        printf("%c please enter an alphabet.\n", x);
    }
    return 0;

    }
    
