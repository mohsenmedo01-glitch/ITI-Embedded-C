#include <stdio.h>
#include <math.h>
int main (void)
{
    int x1;
    int x2;
    int y1;
    int y2;
    printf("enter x1\n");
    scanf("%d", &x1);
    printf("enter x2\n");
    scanf("%d", &x2);
    printf("enter y1\n");
    scanf("%d", &y1);
    printf("enter y2\n");
    scanf("%d", &y2);
    double distance=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

    printf("Distance: %lf\n", distance);

    return 0;
}

