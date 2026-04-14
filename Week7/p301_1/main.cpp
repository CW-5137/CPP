#include <iostream>
#include "MyTime.h"

using namespace std;

int main() {
    MyTime t1, t2, t3;

    cout << "[t1 입력]" << endl;
    t1.read();

    cout << "\n[t2 입력]" << endl;
    t2.read();

    cout << "\nt1 = ";
    t1.print();

    cout << "t2 = ";
    t2.print();

    t3 = t1.add(t2);
    cout << "t3 = t1 + t2 = ";
    t3.print();

    cout << "\n[convert 테스트]" << endl;
    t3.convert(3661.789);
    cout << "3661.789초 변환 결과 = ";
    t3.print();

    cout << "\n[reset 테스트]" << endl;
    t3.reset();
    cout << "reset 후 t3 = ";
    t3.print();

    return 0;
}