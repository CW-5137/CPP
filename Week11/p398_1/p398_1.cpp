#define _CRT_SECURE_NO_WARNINGS  //1학년 씨언어 수업때 배운것
#include <iostream>
#include <cstring>
using namespace std;

class Sample {
private:
    char* name;
    static int count;

public:
    Sample() {
        name = new char[1];
        name[0] = '\0';
        count++;
    }

    Sample(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        count++;
    }

    Sample(const Sample& s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        count++;
    }

    ~Sample() {
        delete[] name;
        count--;
    }

    static void printCount() {
        cout << "현재 객체 수: " << count << endl;
    }
};

int Sample::count = 0;

int main() {
    Sample a("sample");
    Sample b(a);

    Sample::printCount();

    return 0;
}