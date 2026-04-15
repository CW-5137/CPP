#include <iostream>
#include <iomanip>
using namespace std;

class MyTime {
    int hour;
    int min;
    int sec;

public:
    MyTime() {
        hour = min = sec = 0;
    }

    void convert(double duration) {
        int total = (int)duration;

        hour = total / 3600;
        min = (total % 3600) / 60;
        sec = total % 60;
    }

    void print() {
        cout << setfill('0') << setw(2) << hour << ":"
             << setw(2) << min << ":"
             << setw(2) << sec << endl;
    }

    MyTime add(MyTime t) {
        MyTime result;

        result.sec = sec + t.sec;
        result.min = min + t.min + result.sec / 60;
        result.sec %= 60;

        result.hour = hour + t.hour + result.min / 60;
        result.min %= 60;

        return result;
    }

    void reset() {
        hour = min = sec = 0;
    }
};

int main() {
    MyTime t1, t2, t3;

    t1.convert(3661); // 1:01:01
    t2.convert(125);  // 0:02:05

    cout << "t1: ";
    t1.print();

    cout << "t2: ";
    t2.print();

    t3 = t1.add(t2);

    cout << "t3 (합): ";
    t3.print();

    return 0;
}