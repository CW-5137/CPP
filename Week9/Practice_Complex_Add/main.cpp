#include <iostream>
using namespace std;

class Complex {
public:
    int real;
    int imag;

    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    void show() {
        cout << real << " + " << imag << "i" << endl;
    }

    // 3. 멤버 함수 - void 방식
    void addVoid(Complex a, Complex b) {
        real = a.real + b.real;
        imag = a.imag + b.imag;
    }

    // 4. 멤버 함수 - return 방식
    Complex addReturn(Complex b) {
        Complex result;
        result.real = real + b.real;
        result.imag = imag + b.imag;
        return result;
    }

    // 5. 연산자 오버로딩
    Complex operator+(Complex b) {
        Complex result;
        result.real = real + b.real;
        result.imag = imag + b.imag;
        return result;
    }
};

// 1. 일반 함수 - void 방식
void addVoid(Complex a, Complex b, Complex& c) {
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
}

// 2. 일반 함수 - return 방식
Complex addReturn(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

int main() {
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c;

    cout << "a = ";
    a.show();

    cout << "b = ";
    b.show();

    cout << endl;

    // 1. 일반 함수 void 방식
    addVoid(a, b, c);
    cout << "1. 일반 함수 void 결과: ";
    c.show();

    // 2. 일반 함수 return 방식
    c = addReturn(a, b);
    cout << "2. 일반 함수 return 결과: ";
    c.show();

    // 3. 멤버 함수 void 방식
    c.addVoid(a, b);
    cout << "3. 멤버 함수 void 결과: ";
    c.show();

    // 4. 멤버 함수 return 방식
    c = a.addReturn(b);
    cout << "4. 멤버 함수 return 결과: ";
    c.show();

    // 5. 연산자 오버로딩
    c = a + b;
    cout << "5. 연산자 오버로딩 결과: ";
    c.show();

    return 0;
}