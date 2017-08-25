#ifndef __CALCULATE_DAYS__
#define __CALCULATE_DAYS__

typedef enum month {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec} Month;
int calculate_days(int, Month, int);
int is_leap_year(int);

#endif
