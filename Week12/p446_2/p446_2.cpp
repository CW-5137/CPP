#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;
const int MAX_MONSTER = 10;

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

    virtual void move(char map[HEIGHT][WIDTH]) {
        int dir = rand() % 4;

        if (dir == 0) {
            x++;
        }
        else if (dir == 1) {
            x--;
        }
        else if (dir == 2) {
            y++;
        }
        else {
            y--;
        }

        checkPosition();
        eat(map);
    }

    void draw(char screen[HEIGHT][WIDTH]) {
        screen[y][x] = icon;
    }

    virtual void print() {
        cout << name << "(" << icon << ") : " << item << endl;
    }
};

// 기본 좀비
class Zombie : public Monster {
public:
    Zombie(string n, char i, int x, int y)
        : Monster(n, i, x, y) {
    }
};

// 기존 강시: 가로 또는 세로 한 방향으로만 움직이는 느낌
class Jiangshi : public Monster {
protected:
    int dir;

public:
    Jiangshi(string n, char i, int x, int y)
        : Monster(n, i, x, y) {
        dir = rand() % 4;
    }

    void move(char map[HEIGHT][WIDTH]) {
        if (dir == 0) {
            x++;
        }
        else if (dir == 1) {
            x--;
        }
        else if (dir == 2) {
            y++;
        }
        else {
            y--;
        }

        checkPosition();
        eat(map);
    }
};

// 문제 (1) 대각선으로만 움직이는 스몸비
class Smombi : public Monster {
public:
    Smombi(string n, char i, int x, int y)
        : Monster(n, i, x, y) {
    }

    void move(char map[HEIGHT][WIDTH]) {
        int dir = rand() % 4;

        if (dir == 0) {
            x++;
            y++;
        }
        else if (dir == 1) {
            x++;
            y--;
        }
        else if (dir == 2) {
            x--;
            y++;
        }
        else {
            x--;
            y--;
        }

        checkPosition();
        eat(map);
    }
};

// 문제 (2) Jiangshi를 상속한 수퍼 강시
class Siangshi : public Jiangshi {
private:
    int count;

public:
    Siangshi(string n, char i, int x, int y)
        : Jiangshi(n, i, x, y) {
        count = 0;
    }

    void move(char map[HEIGHT][WIDTH]) {
        count++;

        // 5번 움직일 때마다 방향을 바꿈
        if (count % 5 == 0) {
            dir = rand() % 4;
        }

        Jiangshi::move(map);
    }
};

// 문제 (3) 내가 만든 몬스터 클래스
class CrazyMonster : public Monster {
public:
    CrazyMonster(string n, char i, int x, int y)
        : Monster(n, i, x, y) {
    }

    void move(char map[HEIGHT][WIDTH]) {
        int dir = rand() % 4;

        // 한 번에 두 칸씩 움직이는 몬스터
        if (dir == 0) {
            x += 2;
        }
        else if (dir == 1) {
            x -= 2;
        }
        else if (dir == 2) {
            y += 2;
        }
        else {
            y -= 2;
        }

        checkPosition();
        eat(map);
    }
};

class MonsterWorld {
private:
    char map[HEIGHT][WIDTH];
    Monster* monster[MAX_MONSTER];
    int count;
    int moveCount;

public:
    MonsterWorld() {
        count = 0;
        moveCount = 0;

        for (int y = 0; y < HEIGHT; y++) {s
            for (int x = 0; x < WIDTH; x++) {
                map[y][x] = '.';
            }
        }
    }

    ~MonsterWorld() {
        for (int i = 0; i < count; i++) {
            delete monster[i];
        }
    }

    void add(Monster* m) {
        if (count < MAX_MONSTER) {
            monster[count] = m;
            count++;
        }
    }

    int countItems() {
        int result = 0;

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                if (map[y][x] == '.') {
                    result++;
                }
            }
        }

        return result;
    }

    void moveAll() {
        for (int i = 0; i < count; i++) {
            monster[i]->move(map);
        }

        moveCount++;
    }

    void print() {
        char screen[HEIGHT][WIDTH];

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                screen[y][x] = map[y][x];
            }
        }

        for (int i = 0; i < count; i++) {
            monster[i]->draw(screen);
        }

        cout << endl;
        cout << "[ Monster World 3 - 세상의 모든 귀신 ]" << endl;

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                cout << screen[y][x] << ' ';
            }
            cout << endl;
        }

        cout << endl;
        cout << "전체 이동 횟수 = " << moveCount << endl;
        cout << "남은 아이템 수 = " << countItems() << endl;

        for (int i = 0; i < count; i++) {
            monster[i]->print();
        }

        cout << endl;
    }

    void play(int times) {
        for (int i = 0; i < times; i++) {
            print();
            moveAll();

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

    // 기존 몬스터
    game.add(new Zombie("좀비", 'Z', rand() % WIDTH, rand() % HEIGHT));
    game.add(new Jiangshi("강시", 'J', rand() % WIDTH, rand() % HEIGHT));

    // 문제 (1) 스몸비 추가
    game.add(new Smombi("스몸비", 'S', rand() % WIDTH, rand() % HEIGHT));

    // 문제 (2) 상시 추가
    game.add(new Siangshi("상시", 'A', rand() % WIDTH, rand() % HEIGHT));

    // 문제 (3) 나만의 몬스터 추가
    game.add(new CrazyMonster("미친몬스터", 'C', rand() % WIDTH, rand() % HEIGHT));

    // 문제 (4) main에서 객체 생성 후 MonsterWorld에 추가하고 테스트
    game.play(20);

    return 0;
}