#include <iostream>
using namespace std;

class Point {
protected:
    int x, y;

public:
    Point(int xx, int yy) : x(xx), y(yy) { }

    void draw() {
        cout << x << ", " << y << "에 점을 그려라.\n";
    }
};

class Rectangle : public Point {
private:
    int width;
    int height;

public:
    Rectangle(int xx, int yy, int w, int h)
        : Point(xx, yy), width(w), height(h) { }

    void draw() {
        cout << x << "," << y << "에 가로 "
             << width << " 세로 " << height
             << "인 사각형을 그려라.\n";
    }
};

int main() {
    Rectangle r(2, 3, 100, 200);
    r.draw();

    return 0;
}


/*
protected를 private로 바꾸면 Rectangle 클래스에서 x, y에 직접 접근할 수 없다.

Point 클래스의 x, y가 private가 되면 자식 클래스인 Rectangle도
x, y를 사용할 수 없기 때문에 Rectangle의 draw() 함수에서
x와 y를 출력하려고 하면 오류가 난다.*/