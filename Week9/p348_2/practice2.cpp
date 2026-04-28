#include <iostream>
using namespace std;

class MyTime {
private:
    int h;
    int m;
    int s;
    int ms;

public:
    // 2번: 초 단위 실수 시간을 받는 생성자
    MyTime(double duration) {
        h = (int)(duration / 3600);
        duration = duration - h * 3600;

        m = (int)(duration / 60);
        duration = duration - m * 60;

        s = (int)duration;
        duration = duration - s;

        ms = (int)(duration * 1000);
    }

    void print() {
        cout << h << "시간 "
             << m << "분 "
             << s << "초 "
             << ms << "밀리초" << endl;
    }
};

int main() {
    MyTime t1(3661.245);

    cout << "3661.245초 = ";
    t1.print();

    return 0;
}

//  결과: 3661.245초 = 1시간 1분 1초 245밀리초