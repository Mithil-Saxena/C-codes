#include <stdio.h>
struct Date {
    int day;
    int month;
    int year;
};
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return daysInMonth[month - 1];
}
struct Date addDays(struct Date date, int days) {
    while (days > 0) {
        int daysInMonth = getDaysInMonth(date.month, date.year);
        if (date.day + days > daysInMonth) {
            days -= (daysInMonth - date.day + 1);
            date.day = 1;
            date.month++;
            if (date.month > 12) {
                date.month = 1;
                date.year++;
            }
        } else {
            date.day += days;
            days = 0;
        }
    }
    return date;
}
int main() {
    struct Date date;
    
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &date.day, &date.month, &date.year);
    
    struct Date newDate = addDays(date, 45);
    
    printf("Date after 45 days: %02d/%02d/%d\n", 
           newDate.day, newDate.month, newDate.year);
    
    return 0;
}