// p486_8 정리
// 실행용 코드가 아니라 1번 원본 코드, 2번 virtual 적용 코드, 3번 설명을 한 파일에 정리한 것입니다.

#include <iostream>
using namespace std;

class Sample1 {
public:
    Sample1() { }

    void play() {
        cout << "1번 sample" << endl;
    }
};

class Sample2 : public Sample1 {
public:
    Sample2() { }

    void play() {
        cout << "2번 sample" << endl;
    }
};

class Sample3 : public Sample1 {
public:
    Sample3() { }

    void play() {
        cout << "3번 sample" << endl;
    }
};

class Sample4 : public Sample1 {
public:
    Sample4() { }

    void play() {
        cout << "4번 sample" << endl;
    }
};

int main() {
    Sample1* arr[4];

    Sample1* a = new Sample1();
    Sample2* b = new Sample2();
    Sample3* c = new Sample3();
    Sample4* d = new Sample4();

    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;

    for (int i = 0; i < 4; i++) {
        arr[i]->play();
    }

    delete a;
    delete b;
    delete c;
    delete d;

    return 0;
}


// 결과:
// 1번 sample
// 1번 sample
// 1번 sample
// 1번 sample


// arr 배열의 자료형이 Sample1* 이고,
// Sample1의 play()에 virtual이 없어서
// 자식 객체가 들어와도 부모 Sample1의 play()가 실행된다.






//다형성 코드 적용버전

#include <iostream>
using namespace std;

class Sample1 {
public:
    Sample1() { }

    virtual void play() {
        cout << "1번 sample" << endl;
    }
};

class Sample2 : public Sample1 {
public:
    Sample2() { }

    void play() {
        cout << "2번 sample" << endl;
    }
};

class Sample3 : public Sample1 {
public:
    Sample3() { }

    void play() {
        cout << "3번 sample" << endl;
    }
};

class Sample4 : public Sample1 {
public:
    Sample4() { }

    void play() {
        cout << "4번 sample" << endl;
    }
};

int main() {
    Sample1* arr[4];

    arr[0] = new Sample1();
    arr[1] = new Sample2();
    arr[2] = new Sample3();
    arr[3] = new Sample4();

    for (int i = 0; i < 4; i++) {
        arr[i]->play();
    }

    for (int i = 0; i < 4; i++) {
        delete arr[i];
    }

    return 0;
}



// 2) 6행의 play() 함수를 virtual로 수정한 경우 출력 결과

// 1번 sample
// 2번 sample
// 3번 sample
// 4번 sample

// 이유는 Sample1의 play()가 가상 함수가 되면 동적 바인딩이 일어나므로, 부모 포인터 Sample1*로 가리키더라도 실제 객체의 play()가 호출된다.

// 3) play()가 가상 함수이고, arr 배열의 자료형이 Sample2*인 경우
//  -> 컴파일 오류가 발생한다.

// 이유: Sample2* 배열에는 Sample2 객체 포인터만 저장할 수 있는데, 코드에서는 Sample1*, Sample3*, Sample4*도 저장하려고 하기 때문이다.
// 즉, Sample1, Sample3, Sample4는 Sample2의 자식 클래스가 아니므로 Sample2*에 대입할 수 없다.