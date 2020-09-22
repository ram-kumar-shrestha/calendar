
#include "zeller.h" //include file for zeller algorithm
#include "layout.h" //layout of the calendar

void options(){

    printf("=================================\n");
    printf(" Welcome to the Calendar \n");
    printf("=================================\n\n\n");

    int choice;
    char repeat;
    top:
    printf("\nEnter your choice to navigate the calendar\n");
    printf("\t1. View calendar for specific year \n");
    printf("\t2. View calendar for specific month \n");
    printf("\t3. View day name of specific day\n");

    printf("Your choice:\t");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            show_year();
            break;
        case 2:
            show_month();
            break;
        case 3:
            show_dayname();
            break;
        default:
            printf("\n\nEnter your choice correctly: \n");
            goto top;
            break;
    }

    printf("\n\nDo you want to navigate again [y/n]?\n");
    scanf("%s",&repeat);

    if((repeat=='y') || (repeat=='Y') || repeat=='yes'){
        goto top;
    }else{
        return 0;
    }

}

// for year navigation
void show_year(){
    int day_name = 0, day = 1, month = 1, year;

    printf("\nEnter year that you want to see :\t ");
    scanf("%d", &year );

    for(month = 1; month <= 12; month++){
        day_name = calculate_dayname(day, month, year);
        layout(day_name, month, year);
    }
}

// for month navigation
void show_month(){
    int day_name = 0, day = 1, month, year;

    printf("\nEnter the date that you want to see : (mm/yy)\t ");
    scanf("%d/%d", &month, &year );


    day_name = calculate_dayname(day, month, year);
    layout(day_name, month, year);
}

// for day name navigation
void show_dayname(){
    int day_name = 0, day, month, year;

    printf("\nEnter the date that you want to see : (dd/mm/yy)\t ");
    scanf("%d/%d/%d", &day, &month, &year );

    char day_name_string[20];

    day_name = calculate_dayname(day, month, year);

    switch(day_name){
        case 1:
            strcpy(day_name_string, "Sunday");
            break;
        case 2:
            strcpy(day_name_string, "Monday");
            break;
        case 3:
            strcpy(day_name_string, "Tuesday");
            break;
        case 4:
            strcpy(day_name_string, "Wednesday");
            break;
        case 5:
            strcpy(day_name_string, "Thursday");
            break;
        case 6:
            strcpy(day_name_string, "Friday");
            break;
        default:
            strcpy(day_name_string, "Saturday");
            break;
    }
    printf("\n%s", day_name_string);
}
