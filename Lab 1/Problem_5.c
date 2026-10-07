#include <stdio.h>
int main(void)
{
    int seconds;
    printf("enter seconds\n");
    scanf("%d", &seconds);
    int hours=seconds/3600;
    int remaining_minutes=seconds%3600; // det rest of the hour 
    printf("Hours: %d\n", hours);
    int minutes=remaining_minutes/60;   // use the rest of the hour to det minutes
    printf("Minutes: %d\n", minutes);
    int second=remaining_minutes%60;         // use the rest of the minute to det seconds
    printf("Seconds: %d\n", second);
    return 0;
}