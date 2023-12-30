
#include <stdio.h>
int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int count_leap_years(int start, int end) {
    int count = 0;
    int year;
    for (year = start; year <= end; year++) {
        if (is_leap_year(year)) {
            count++;
        }
    }
    return count;
}
int main() {
    printf("%d\n", count_leap_years(1, 23)); 
    printf("%d\n", count_leap_years(345, 4567));
    return 0;
}
