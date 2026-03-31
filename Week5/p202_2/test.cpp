#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomMap(int map[5][5]);
void printMap(int map[5][5]);
void checkMap(int map[5][5]);

int main() {
    int map[5][5];

    srand(time(NULL));   // 랜덤 시드 설정

    randomMap(map);
    printMap(map);
    checkMap(map);

    return 0;
}

// (1) 5x5 배열에 0과 1을 랜덤으로 채우는 함수
void randomMap(int map[5][5]) {
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            map[i][j] = rand() % 2;   // 0 또는 1
        }
    }
}

// (2) 체커보드를 보기 좋게 출력하는 함수
void printMap(int map[5][5]) {
    int i, j;

    printf("=== Checker Board ===\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// (3) 가로, 세로, 대각선이 모두 0이거나 모두 1인 부분 찾기
void checkMap(int map[5][5]) {
    int i, j;
    int same;

    printf("=== Check Result ===\n");

    // 가로 검사
    for (i = 0; i < 5; i++) {
        same = 1;
        for (j = 1; j < 5; j++) {
            if (map[i][0] != map[i][j]) {
                same = 0;
                break;
            }
        }
        if (same) {
            printf("%d번째 가로줄: 모두 %d\n", i + 1, map[i][0]);
        }
    }

    // 세로 검사
    for (j = 0; j < 5; j++) {
        same = 1;
        for (i = 1; i < 5; i++) {
            if (map[0][j] != map[i][j]) {
                same = 0;
                break;
            }
        }
        if (same) {
            printf("%d번째 세로줄: 모두 %d\n", j + 1, map[0][j]);
        }
    }

    // 왼쪽 위 -> 오른쪽 아래 대각선 검사
    same = 1;
    for (i = 1; i < 5; i++) {
        if (map[0][0] != map[i][i]) {
            same = 0;
            break;
        }
    }
    if (same) {
        printf("주대각선: 모두 %d\n", map[0][0]);
    }

    // 오른쪽 위 -> 왼쪽 아래 대각선 검사
    same = 1;
    for (i = 1; i < 5; i++) {
        if (map[0][4] != map[i][4 - i]) {
            same = 0;
            break;
        }
    }
    if (same) {
        printf("부대각선: 모두 %d\n", map[0][4]);
    }
}