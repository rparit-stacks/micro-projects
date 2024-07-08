#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char studentName[99];
    int class;
    char section;
    int Mathematics, English, Hindi, Science, socialScience;

    printf("Enter Your Name : ");
    scanf("%99[^ \t\n]", studentName);
    while ((getchar()) != '\n')
        ;
    printf("Enter Your Class(eg. 11) : ");
    scanf("%d", &class);
    while ((getchar()) != '\n')
        ;
    printf("Enter Your section (eg. A) : ");
    scanf("%c", &section);
    while ((getchar()) != '\n')
        ;

    printf("Enter Your Marks in Mathematics : ");
    scanf("%d", &Mathematics);
    while ((getchar()) != '\n')
        ;
    printf("Enter Your Marks in Science : ");
    scanf("%d", &Science);
    while ((getchar()) != '\n')
        ;
    printf("Enter Your Marks in Social Science : ");
    scanf("%d", &socialScience);
    while ((getchar()) != '\n')
        ;
    printf("Enter Your Marks in English : ");
    scanf("%d", &English);
    printf("Enter Your Marks in Hindi : ");
    scanf("%d", &Hindi);

    printf("-----------------------------------------------------------\n\n");
    printf("            Jawahar Navodaya Vidyalaya \n");
    printf("                 Annual Report Card \n\n");
    printf("           Name: %s \n", studentName);
    printf("           Standard: %d\n", class);
    printf("           Section: %c\n\n", section);
    printf("           Marks Secured out of 100\n");
    printf("         Mathematics: %d\n\t English: %d\n\t Hindi: %d\n\t Science: %d\n\t Social Science: %d\n\n", Mathematics, English, Hindi, Science, socialScience);
    printf("          Total marks secured: %d\n", Mathematics + English + socialScience + Science + Hindi);

    int sum = Mathematics + English + socialScience + Science + Hindi;

    if (sum >= 450 && sum <= 500)
        printf("Grade A\n");
    if (sum >= 400 && sum <= 449)
        printf("Grade B\n");
    if (sum >= 350 && sum <= 399)
        printf("Grade C\n");
    if (sum >= 300 && sum <= 349)
        printf("Grade D\n");
    if (sum >= 200 && sum <= 299)
        printf("Grade E\n");
    if (sum <= 199)
        printf("Grade F\n");
    else
        return 0;

    printf("------------------------------------------------------------");
    return 0;
}