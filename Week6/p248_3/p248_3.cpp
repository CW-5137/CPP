void addTime(MyTime t1, MyTime t2, MyTime* pt) {
    pt->hour = t1.hour + t2.hour;
    pt->min = t1.min + t2.min;
    pt->sec = t1.sec + t2.sec;

    if (pt->sec >= 60) {
        pt->min += pt->sec / 60;
        pt->sec %= 60;
    }

    if (pt->min >= 60) {
        pt->hour += pt->min / 60;
        pt->min %= 60;
    }
}