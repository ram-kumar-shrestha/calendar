#include <math.h>

int calculate_dayname(int day, int month, int year){

    int h,k,j;

    if((month == 1) || (month == 2) ){
        month += 12;
        year -=1;
    }
    k = year%100; // if year = 1920 -> k = 20
    j = year/100; // if year = 1920 -> k = 19

    // Zeller's Algorithm
    h = (day + (13*(month+1))/5 + k + k/4 + j/4 + 5*j) % 7 ;

    /*
        h = 0 - saturday, 1 -sunday ....
        month = 3 - march, ..... , february = 14
    */
    return h;
}

