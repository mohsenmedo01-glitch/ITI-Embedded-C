#include <stdio.h>

struct Student
{
    char name[20];
    int age;
    float marks;
};

int main()
{
    struct Student s[100], temp;
    int n, i, j;
    float sum = 0, avg, max;
    printf("Enter number of students ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter name: ");
        scanf("%19s", s[i].name);
        printf("Enter age: ");
        scanf("%d", &s[i].age);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
        sum = sum + s[i].marks;
    }
    printf("\n Students Information \n");

    for (i = 0; i < n; i++)
    {
        printf("\nName: %s\n", s[i].name);
        printf("Age: %d\n", s[i].age);
        printf("Marks: %.2f\n", s[i].marks);
    }

    avg = sum / n;

    printf("\nAverage = %.2f\n", avg);
    max = s[0].marks;

    for (i = 1; i < n; i++)
    {
        if (s[i].marks > max)
        {
            max = s[i].marks;
        }
    }

    printf("Highest Marks = %.2f\n", max);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i].marks < s[j].marks)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("\n Top 3 Students \n");

    for (i = 0; i < n && i < 3; i++)
    {
        printf("\nRank: %d\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n", s[i].marks);
    }

    return 0;
}