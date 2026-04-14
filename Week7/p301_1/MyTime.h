#ifndef MYTIME_H
#define MYTIME_H

class MyTime {
private:
    int hour;
    int minute;
    int second;
    int millisecond;

public:
    MyTime();

    void convert(double duration);
    void print();
    MyTime add(MyTime t);
    void reset();
    void read();
};

#endif