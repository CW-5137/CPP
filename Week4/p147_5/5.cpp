#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int people, n, bullet;
    cout << "사람 수 입력: ";
    cin >> people;
    cout << "탄창 수 입력: ";
    cin >> n;
    cout << "총알 수 입력: ";
    cin >> bullet;

    if (bullet > n) {
        cout << "총알 수는 탄창 수보다 많을 수 없습니다." << endl;
        return 0;
    }

    if (bullet > people) {
        cout << "총알 수는 사람 수보다 많을 수 없습니다." << endl;
        return 0;
    }

    int gun[100] = {0};     // 탄창, 0은 빈칸, 1은 총알
    int alive[100];         // 생존 여부, 1은 생존, 0은 탈락

    for (int i = 0; i < people; i++) {
        alive[i] = 1;
    }

    // 총알 랜덤으로 넣기
    int count = 0;
    while (count < bullet) {
        int r = rand() % n;
        if (gun[r] == 0) {
            gun[r] = 1;
            count++;
        }
    }

    int chamber = 0;   // 현재 탄창 위치
    int player = 0;    // 현재 사람 번호
    int fired = 0;     // 발사된 총알 수

    cout << "\n게임 시작\n";

    while (fired < bullet) {
        if (alive[player] == 1) {
            cout << player + 1 << "번 사람 차례: ";

            if (gun[chamber] == 1) {
                cout << "빵! 탈락" << endl;
                alive[player] = 0;
                gun[chamber] = 0;
                fired++;
            } else {
                cout << "찰칵! 생존" << endl;
            }

            chamber++;
            if (chamber == n) {
                chamber = 0;
            }
        }

        player++;
        if (player == people) {
            player = 0;
        }
    }

    cout << "\n게임 끝\n";
    cout << "생존자: ";
    for (int i = 0; i < people; i++) {
        if (alive[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}