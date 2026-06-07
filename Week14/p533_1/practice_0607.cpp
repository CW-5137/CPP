//예제 1. 생성자와 소멸자
// #include <iostream>
// using namespace std;

// class Dog {
//     public:
//         Dog() {
//             cout << "Dog 생성자" << endl;
//         }

//         ~Dog() {
//             cout << "Dog 소멸자" << endl;
//         }
// };

// int main() {
//     cout << "main 시작" << endl;

//     Dog d;

//     cout << "main 끝" << endl;

//     return 0;
// }


//예제 2. 객체가 여러 개일 때 생성자/소멸자 순서
// #include <iostream>
// using namespace std;

// class Dog {
//     public:
//         Dog() {
//             cout << "Dog 생성자" << endl;
//         }

//         ~Dog() {
//             cout << "Dog 소멸자" << endl;
//         }
// };

// int main() {
//     Dog d1;
//     Dog d2;

//     return 0;
// }


//예제 3. 상속에서 생성자/소멸자 순서
// #include <iostream>
// using namespace std;

// class Animal {
//     public:
//         Animal() {
//             cout << "Animal 생성자" << endl;
//         }

//         ~Animal() {
//             cout << "Animal 소멸자" << endl;
//         }
// };

// class Dog : public Animal {
//     public:
//         Dog() {
//             cout << "Dog 생성자" << endl;
//         }

//         ~Dog() {
//             cout << "Dog 소멸자" << endl;
//         }
// };

// int main() {
//     Dog d;

//     return 0;
// }

//부모 먼저 생성 → 자식 생성
//자식 먼저 소멸 → 부모 소멸



//예제 4. 오버라이딩
// #include <iostream>
// using namespace std;

// class Animal {
//     public:
//         void sound() {
//             cout << "동물 소리" << endl;
//         }
// };
       
// class Dog : public Animal {
//     public:
//         void sound() {
//             cout << "멍멍" << endl;
//         }
// };

// int main() {
//     Dog d;
//     d.sound();

//     return 0;
// }



//예제 5. 부모 포인터 + virtual 없음
/*#include <iostream>
using namespace std;

class Animal {
    public:
        void sound() {
            cout << "동물 소리" << endl;
        }
};

class Dog : public Animal {
    public:
        void sound() {
            cout << "멍멍" << endl;
        }
};

int main() {
    Dog d;

    Animal* p = &d;

    p->sound();

    return 0;
} 
*/


//예제 6. 부모 포인터 + virtual 있음
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "동물 소리" << endl;
    }
};

class Dog : public Animal {
    public:
    void sound() {
        cout << "멍멍" << endl;
    }
};

int main() {
    Dog d;

    Animal* p = &d;

    p->sound();

    return 0;
}