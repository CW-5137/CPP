#include <iostream>
#include <iomanip>
#include "MyTime.h"

using namespace std;

// 기본 생성자
MyTime::MyTime() {
    hour = 0;
    minute = 0;
    second = 0;
    millisecond = 0;
}

// 초 단위 시간을 시:분:초:밀리초로 변환
void MyTime::convert(double duration) {
    int totalMilliseconds = (int)(duration * 1000 + 0.5); // 반올림

    hour = totalMilliseconds / 3600000;
    totalMilliseconds %= 3600000;

    minute = totalMilliseconds / 60000;
    totalMilliseconds %= 60000;

    second = totalMilliseconds / 1000;
    millisecond = totalMilliseconds % 1000;
}

// 시간 출력
void MyTime::print() {
    cout << setfill('0')
         << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second << ":"
         << setw(3) << millisecond << endl;
}

// 두 시간 더하기
MyTime MyTime::add(MyTime t) {
    MyTime result;

    int total1 = ((hour * 3600) + (minute * 60) + second) * 1000 + millisecond;
    int total2 = ((t.hour * 3600) + (t.minute * 60) + t.second) * 1000 + t.millisecond;

    int sum = total1 + total2;

    result.convert(sum / 1000.0);

    return result;
}

// 초기화
void MyTime::reset() {
    hour = 0;
    minute = 0;
    second = 0;
    millisecond = 0;
}

// 사용자 입력
void MyTime::read() {
    cout << "시간(hour) 입력: ";
    cin >> hour;

    cout << "분(minute) 입력: ";
    cin >> minute;

    cout << "초(second) 입력: ";
    cin >> second;

    cout << "밀리초(millisecond) 입력: ";
    cin >> millisecond;
}