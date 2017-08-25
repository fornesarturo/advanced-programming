#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "calculate_days.h"

/** is_leap_year
  * Given a year 'year' return 1 if it is a leap year, 0 otherwise.
  * @param:
  *  year: year
  * @return:
  *  int: 1 || 0
*/
int is_leap_year(int year) {
    assert(year > 0);
    if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }

    return 0;
}

/** calculate_days
  * Given a month 'month' and a day in that month 'month_day' return the
  * the days passed from the start of the year to that particular date.
  * @param:
  *  month: month
  *  day: day of the month
  * @return:
  *  int: number of days
*/
int calculate_days(int day, Month month, int year) {
    int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(is_leap_year(year)) { days_per_month[Feb] += 1; }
    assert(day >= 1 && day <= days_per_month[month]);

    int days_passed = day;

    for (Month i = Jan; i < month; i++) {
        days_passed += days_per_month[i];
    }

    return days_passed;
}
