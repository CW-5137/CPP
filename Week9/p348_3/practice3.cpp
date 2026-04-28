#include <iostream>
using namespace std;

class Monster {
private:
    int x;
    int y;
    int nEnergy;

public:
    Monster(int x = 0, int y = 0)
        : x(x), y(y), nEnergy(1000) {
    }

    void move(int dx, int dy) {
        x = x + dx;
        y = y + dy;
    }

    void eat(bool ateItem) {
        if (ateItem == true) {
            nEnergy = nEnergy + 8;
        }
        else {
            nEnergy = nEnergy - 1;
        }
    }

    void print() {
        cout << "몬스터 위치: (" << x << ", " << y << ")" << endl;
        cout << "몬스터 에너지: " << nEnergy << endl;
    }
};

int main() {
    Monster monster(0, 0);

    cout << "처음 상태" << endl;
    monster.print();

    cout << endl;

    monster.move(1, 0);
    monster.eat(false);

    cout << "아이템을 못 먹고 이동한 후" << endl;
    monster.print();

    cout << endl;

    monster.eat(true);

    cout << "아이템을 먹은 후" << endl;
    monster.print();

    return 0;
}


// 결과: 
// 처음 상태
// 몬스터 위치: (0, 0)
// 몬스터 에너지: 1000

// 아이템을 못 먹고 이동한 후
// 몬스터 위치: (1, 0)
// 몬스터 에너지: 999

// 아이템을 먹은 후
// 몬스터 위치: (1, 0)
// 몬스터 에너지: 1007