#include <math.h>
#include <stdbool.h>
char month_name[40];
int limit = 30;


void layout(int day_name, int month, int year) {

    // name of the month
    show_month_name(month, year);
    printf("\n\n%s\n", month_name);

    // displays a row of days' name
    printf("|Sun|\t|Mon|\t|Tue|\t|Wed|\t|Thu|\t|Fri|\t|Sat| \n");

    int day = 1, counter = 0, i=0;
    //gives the right position for the first day of the month
    int show_first_day(tab){

        for(i=1; i<tab; i++){
                printf("\t");
        }
        printf("  %d\t", day);
    }

    switch(day_name){
        case 0:
            counter = 7; // counter to change the row
            show_first_day(7);
            break;
        case 2:
            counter = 2;
            show_first_day(2);
            break;
        case 3:
            counter = 3;
            show_first_day(3);
            break;
        case 4:
            counter = 4;
            show_first_day(4);
            break;
        case 5:
            counter = 5;
            show_first_day(5);
            break;
        case 6:
            counter = 6;
            show_first_day(6);
            break;
        default:
            counter = 1;
            show_first_day(0);
            break;

    }

    //Prints day of a month from 2nd day
    for(day=2; day<= limit; day++){
        if(counter == 7){
            printf("\n"); //changes the row
            counter = 0;
        }        printf(" %d\t ",day);
        counter++;
    }
}

// prints the name of the month and limit the no of days
void show_month_name(int month, int year){
    switch(month){
        case 1:
            limit = 31;
            strcpy(month_name, "January");
            break;
        case 2:
            if( is_leap(year) ){
                limit = 29;
            }else{
                limit = 28;
            }
            strcpy(month_name, "February");
            break;
        case 3:
            limit = 31;
            strcpy(month_name, "March");
            break;
        case 4:
            limit = 30;
            strcpy(month_name, "April");
            break;
        case 5:
            limit = 31;
            strcpy(month_name, "May");
            break;
        case 6:
            limit = 30;
            strcpy(month_name, "June");
            break;
        case 7:
            limit = 31;
            strcpy(month_name, "July");
            break;
        case 8:
            limit = 31;
            strcpy(month_name, "August");
            break;
        case 9:
            limit = 30;
            strcpy(month_name, "September");
            break;
        case 10:
            limit = 31;
            strcpy(month_name, "October");
            break;
        case 11:
            limit = 30;
            strcpy(month_name, "November");
            break;
        default:
            limit = 31;
            strcpy(month_name, "December");
            break;
    }
}

int is_leap(int year){

    if(year % 400 == 0 ) {
        return true;
    } else if(year % 100 == 0){
        return false;
    }else if(year % 4 == 0){
        return true;
    }else{
        return false;
    }

}

