#include<stdio.h>
#include<stdint.h>

typedef struct {
    uint16_t day;
    uint16_t month;
    uint16_t year;
} Date;

Date date = {3, 1, 2000}; //Thu 2
Date dateCurent = {7, 9, 2023};

uint16_t soNgay = 0;
int isLeapYear(int nam) {
    return ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0));
}

int ngayTrongThang(int month, int nam) {
    switch (month) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(nam) ? 29 : 28;
        default:
            return 31;
    }
}

int tongSoNgay(uint16_t endDay, uint16_t endMonth, uint16_t endYear) {
    int days = 0;

    while (date.day != endDay || date.month != endMonth || date.year != endYear) {
        days++;
        if (date.day < ngayTrongThang(date.month, date.year)) {
            date.day++;
        } 
        else {
            if (date.month < 12) {
                date.month++;
                date.day = 1;
            } else {
                date.month = 1;
                date.year++;
                date.day = 1;
            }
        }
    }
    return days;
}


int main() {
    int tongNgay = tongSoNgay(dateCurent.day,dateCurent.month,dateCurent.year);
    int layDu = tongNgay % 7;

    switch (layDu) {
        case 0:
            printf("%d: T2",tongNgay);
            return 0;
        case 1:
            printf("%d: T3",tongNgay);
            return 0;
        case 2: 
            printf("%d: T4",tongNgay);
            return 0;
        case 3:
            printf("%d: T5",tongNgay);
            return 0;
        case 4:
            printf("%d: T6",tongNgay);
            return 0;
        case 5:
            printf("%d: T7",tongNgay);
            return 0;
        case 6:
            printf("%d: CN",tongNgay);
            return 0;
        default:
            return 0;
    }
    return 0;
}