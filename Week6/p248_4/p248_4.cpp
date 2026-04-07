#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

static int MineMapMask[40][80];
static int MineMapLabel[40][80];

void printMap(int row, int col) {
    cout << "   ";
    for (int j = 0; j < col; j++) {
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < row; i++) {
        cout << i << " ";
        if (i < 10) cout << " ";
        for (int j = 0; j < col; j++) {
            if (MineMapLabel[i][j] == 1)
                cout << "* ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

int main() {
    int row, col, mineCount;

    srand(time(0));

    cout << "가로 크기 입력(최대 80): ";
    cin >> col;
    cout << "세로 크기 입력(최대 40): ";
    cin >> row;
    cout << "지뢰 개수 입력: ";
    cin >> mineCount;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            MineMapMask[i][j] = 0;
            MineMapLabel[i][j] = 0;
        }
    }

    for (int k = 0; k < mineCount; k++) {
        int r = rand() % row;
        int c = rand() % col;

        if (MineMapLabel[r][c] == 0)
            MineMapLabel[r][c] = 1;
        else
            k--;
    }

    printMap(row, col);

    return 0;
}