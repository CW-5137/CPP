#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

class Monster {
private:
    string name;
    char shape;
    int x;
    int y;
    int energy;

    static int count;

public:
    Monster(string n, char s, int px, int py) {
        name = n;
        shape = s;
        x = px;
        y = py;
        energy = 50;

        count++;
    }

    ~Monster() {
        count--;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    char getShape() {
        return shape;
    }

    int getEnergy() {
        return energy;
    }

    void move(int width, int height) {
        int dir = rand() % 4;

        if (dir == 0 && y > 0) {
            y--;
        }
        else if (dir == 1 && y < height - 1) {
            y++;
        }
        else if (dir == 2 && x > 0) {
            x--;
        }
        else if (dir == 3 && x < width - 1) {
            x++;
        }

        energy -= 10;
    }

    void print() {
        cout << name << " " << shape << " E:" << energy << endl;
    }

    static void printCount() {
        cout << "전체 몬스터의 수 = " << count << endl;
    }
};

int Monster::count = 0;

class MonsterWorld {
private:
    int width;
    int height;
    int nMon;
    int moveCount;

    Monster* pMon[10];

public:
    MonsterWorld(int w, int h) {
        width = w;
        height = h;
        nMon = 0;
        moveCount = 0;
    }

    ~MonsterWorld() {
        for (int i = 0; i < nMon; i++) {
            delete pMon[i];
        }
    }

    void addMonster(string name, char shape, int x, int y) {
        pMon[nMon] = new Monster(name, shape, x, y);
        nMon++;
    }

    void checkStarvation() {
        for (int i = 0; i < nMon; i++) {
            if (pMon[i]->getEnergy() <= 0) {
                delete pMon[i];

                pMon[i] = pMon[nMon - 1];
                nMon--;

                cout << "Monster 하나가 굶어죽었습니다" << endl;

                i--;
            }
        }
    }

    void move() {
        for (int i = 0; i < nMon; i++) {
            pMon[i]->move(width, height);
        }

        moveCount++;
    }

    void print() {
        system("cls");

        char map[10][20];

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                map[y][x] = '.';
            }
        }

        for (int i = 0; i < nMon; i++) {
            int x = pMon[i]->getX();
            int y = pMon[i]->getY();

            map[y][x] = pMon[i]->getShape();
        }

        cout << "[ Monster World ]" << endl;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                cout << map[y][x];
            }
            cout << endl;
        }

        cout << endl;
        cout << "전체 이동 횟수 = " << moveCount << endl;
        cout << "남은 아이템 수 = 1" << endl;

        for (int i = 0; i < nMon; i++) {
            pMon[i]->print();
        }

        Monster::printCount();
    }

    void play() {
        for (int i = 0; i < 10; i++) {
            move();
            checkStarvation();
            print();

            Sleep(700);
        }
    }
};

int main() {
    srand((unsigned int)time(NULL));

    MonsterWorld game(20, 10);

    game.addMonster("몬스터1", 'M', 3, 3);
    game.addMonster("몬스터2", 'A', 10, 5);
    game.addMonster("몬스터3", 'B', 15, 7);

    game.play();

    return 0;
}