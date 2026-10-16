// used Vibe coding not ai 
#include <stdio.h>
#include <string.h>

enum Department
{
    IT,
    HR,
    FINANCE
};

enum EmployeeType
{
    FULL_TIME,
    PART_TIME,
    INTERN
};

union Compensation
{
    float hourly_rate;
    float monthly_salary;
};

struct Employee
{
    int id;
    char name[50];
    enum Department department;
    enum EmployeeType type;
    union Compensation compensation;
};

int main()
{
    struct Employee employees[100];

    int count = 0;
    int choice, i, j;
    int id, department, type;
    int found;

    do
    {
        printf("\n--- Employee Management System ---\n");
        printf("Add Employee\n");
        printf("Remove Employee\n");
        printf("Search Employee by ID\n");
        printf("Filter by Department\n");
        printf("Filter by Employee Type\n");
        printf("Calculate Total Payroll\n");
        printf("Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count == 100)
                {
                    printf("Employee list is full!\n");
                    break;
                }

                printf("Enter ID: ");
                scanf("%d", &employees[count].id);

                printf("Enter name: ");
                scanf(" %49[^\n]", employees[count].name);

                printf("Department (0=IT, 1=HR, 2=FINANCE): ");
                scanf("%d", &department);

                if (department < 0 || department > 2)
                {
                    printf("Invalid department!\n");
                    break;
                }

                employees[count].department = department;

                printf("Type (0=FULL_TIME, 1=PART_TIME, 2=INTERN): ");
                scanf("%d", &type);

                if (type < 0 || type > 2)
                {
                    printf("Invalid employee type!\n");
                    break;
                }

                employees[count].type = type;

                if (employees[count].type == FULL_TIME)
                {
                    printf("Enter monthly salary: ");
                    scanf("%f",
                          &employees[count].compensation.monthly_salary);
                }
                else
                {
                    printf("Enter hourly rate: ");
                    scanf("%f",
                          &employees[count].compensation.hourly_rate);
                }

                count++;

                printf("Employee added successfully!\n");
                break;

            case 2:
                printf("Enter ID to remove: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (employees[i].id == id)
                    {
                        for (j = i; j < count - 1; j++)
                        {
                            employees[j] = employees[j + 1];
                        }

                        count--;
                        found = 1;

                        printf("Employee removed!\n");
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Employee not found!\n");
                }
                break;

            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (employees[i].id == id)
                    {
                        printf("\nID: %d\n", employees[i].id);
                        printf("Name: %s\n", employees[i].name);

                        printf("Department: ");
                        if (employees[i].department == IT)
                            printf("IT\n");
                        else if (employees[i].department == HR)
                            printf("HR\n");
                        else
                            printf("FINANCE\n");

                        printf("Type: ");
                        if (employees[i].type == FULL_TIME)
                        {
                            printf("FULL_TIME\n");
                            printf("Monthly Salary: %.2f\n",
                                employees[i].compensation.monthly_salary);
                        }
                        else if (employees[i].type == PART_TIME)
                        {
                            printf("PART_TIME\n");
                            printf("Hourly Rate: %.2f\n",
                                employees[i].compensation.hourly_rate);
                        }
                        else
                        {
                            printf("INTERN\n");
                            printf("Hourly Rate: %.2f\n",
                                employees[i].compensation.hourly_rate);
                        }

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Employee not found!\n");
                }
                break;

            case 4:
                printf("Enter department (0=IT, 1=HR, 2=FINANCE): ");
                scanf("%d", &department);

                if (department < 0 || department > 2)
                {
                    printf("Invalid department!\n");
                    break;
                }

                for (i = 0; i < count; i++)
                {
                    if (employees[i].department == department)
                    {
                        printf("ID: %d, Name: %s\n",
                               employees[i].id,
                               employees[i].name);
                    }
                }
                break;

            case 5:
                printf("Enter type (0=FULL_TIME, 1=PART_TIME, 2=INTERN): ");
                scanf("%d", &type);

                if (type < 0 || type > 2)
                {
                    printf("Invalid employee type!\n");
                    break;
                }

                for (i = 0; i < count; i++)
                {
                    if (employees[i].type == type)
                    {
                        printf("ID: %d, Name: %s\n",
                               employees[i].id,
                               employees[i].name);
                    }
                }
                break;

            case 6:
            {
                float totalPayroll = 0;
                float hours;

                printf("Enter monthly working hours: ");
                scanf("%f", &hours);

                for (i = 0; i < count; i++)
                {
                    if (employees[i].type == FULL_TIME)
                    {
                        totalPayroll +=
                            employees[i].compensation.monthly_salary;
                    }
                    else
                    {
                        totalPayroll +=
                            employees[i].compensation.hourly_rate * hours;
                    }
                }

                printf("Total Monthly Payroll = %.2f\n", totalPayroll);
                break;
            }

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}