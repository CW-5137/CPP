#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;
const int MAX = 20;

// 몬스터 클래스
class Monster {
protected:
    string name;
    char icon;
    int x;
    int y;
    int item;

public:
    Monster(string n = "몬스터", char i = 'M', int px = 0, int py = 0) {
        name = n;
        icon = i;
        x = px;
        y = py;
        item = 0;
    }

    virtual ~Monster() {
    }

    virtual void move(char key) {
        int dir = rand() % 4;

        if (dir == 0) {
            y--;
        }
        else if (dir == 1) {
            y++;
        }
        else if (dir == 2) {
            x--;
        }
        else {
            x++;
        }

        checkPosition();
    }

    void checkPosition() {
        if (x < 0) {
            x = 0;
        }

        if (x >= WIDTH) {
            x = WIDTH - 1;
        }

        if (y < 0) {
            y = 0;
        }

        if (y >= HEIGHT) {
            y = HEIGHT - 1;
        }
    }

    void eat(char map[HEIGHT][WIDTH]) {
        if (map[y][x] == '.') {
            map[y][x] = ' ';
            item++;
        }
    }

    void draw(char screen[HEIGHT][WIDTH]) {
        screen[y][x] = icon;
    }

    void print() {
        cout << name << "(" << icon << ") : " << item << endl;
    }
};

// 사람이 움직이는 클래스
class Tuman : public Monster {
private:
    char upKey;
    char downKey;
    char leftKey;
    char rightKey;

public:
    Tuman(string n, char i, int px, int py,
          char up, char down, char left, char right)
        : Monster(n, i, px, py) {
        upKey = up;
        downKey = down;
        leftKey = left;
        rightKey = right;
    }

    void move(char key) {
        if (key == upKey) {
            y--;
        }
        else if (key == downKey) {
            y++;
        }
        else if (key == leftKey) {
            x--;
        }
        else if (key == rightKey) {
            x++;
        }

        checkPosition();
    }
};

// 몬스터 월드 클래스
class MonsterWorld {
private:
    char map[HEIGHT][WIDTH];
    Monster* pMon[MAX];
    int nMon;
    int nMove;

public:
    MonsterWorld() {
        nMon = 0;
        nMove = 0;

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                map[y][x] = '.';
            }
        }
    }

    ~MonsterWorld() {
        for (int i = 0; i < nMon; i++) {
            delete pMon[i];
        }
    }

    void add(Monster* m) {
        pMon[nMon] = m;
        nMon++;
    }

    int countItems() {
        int count = 0;

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                if (map[y][x] == '.') {
                    count++;
                }
            }
        }

        return count;
    }

    void moveAll(char key) {
        for (int i = 0; i < nMon; i++) {
            pMon[i]->move(key);
            pMon[i]->eat(map);
        }

        nMove++;
    }

    void print() {
        char screen[HEIGHT][WIDTH];

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                screen[y][x] = map[y][x];
            }
        }

        for (int i = 0; i < nMon; i++) {
            pMon[i]->draw(screen);
        }

        cout << endl;
        cout << "[ Monster World - 두 사람 경쟁 ]" << endl;

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                cout << screen[y][x] << ' ';
            }
            cout << endl;
        }

        cout << endl;
        cout << "전체 이동 횟수 = " << nMove << endl;
        cout << "남은 아이템 수 = " << countItems() << endl;

        for (int i = 0; i < nMon; i++) {
            pMon[i]->print();
        }

        cout << endl;
        cout << "왼쪽 사람 이동: w a s d" << endl;
        cout << "오른쪽 사람 이동: i j k l" << endl;
        cout << "종료: q" << endl;
    }

    void play() {
        char key;

        while (true) {
            print();

            cout << "키 입력: ";
            cin >> key;

            if (key == 'q') {
                break;
            }

            moveAll(key);

            if (countItems() == 0) {
                break;
            }
        }

        cout << "게임 종료" << endl;
    }
};

int main() {
    srand((unsigned int)time(NULL));

    MonsterWorld game;

    // 일반 몬스터 추가
    game.add(new Monster("좀비", 'Z', rand() % WIDTH, rand() % HEIGHT));
    game.add(new Monster("고스트", 'G', rand() % WIDTH, rand() % HEIGHT));
    game.add(new Monster("도깨비", 'D', rand() % WIDTH, rand() % HEIGHT));

    // 마지막 두 개는 사람
    // 문제에서 말한 pMon[nMon-2], pMon[nMon-1]에 해당함

    // 왼쪽 사람: w a s d
    game.add(new Tuman("왼쪽사람", 'L', 1, 1, 'w', 's', 'a', 'd'));

    // 오른쪽 사람: 원래는 화살표지만 초보자용으로 i j k l 사용
    game.add(new Tuman("오른쪽사람", 'R', WIDTH - 2, 1, 'i', 'k', 'j', 'l'));

    game.play();

    return 0;
}