#include <iostream>
using namespace std;

class MyTime {
private:
    int h;
    int m;
    int s;
    int ms;

public:
    // 1번: 생성자
    // 매개변수가 없으면 전부 0으로 초기화
    // 멤버 초기화 리스트 사용
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0)
        : h(h), m(m), s(s), ms(ms) {
    }

    void print() {
        cout << h << "시간 "
             << m << "분 "
             << s << "초 "
             << ms << "밀리초" << endl;
    }
};

int main() {
    MyTime t1;
    MyTime t2(1, 2, 3, 4);

    cout << "t1: ";
    t1.print();

    cout << "t2: ";
    t2.print();

    return 0;
}

//t1: 0시간 0분 0초 0밀리초
//t2: 1시간 2분 3초 4밀리초