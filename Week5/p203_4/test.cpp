#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 5
#define MAX_MOVES 10000
#define RANK_FILE "ranking.dat"
#define SAVE_FILE "puzzle_save.dat"

typedef struct {
    char name[20];
    int size;
    int moveCount;
    int seconds;
} RankRecord;

typedef struct {
    int size;
    int board[MAX][MAX];
    int initialBoard[MAX][MAX];
    int blankR, blankC;
    int moveCount;
    char moves[MAX_MOVES];
    time_t startTime;
    int elapsedBeforeSave;
} SaveData;

void copyBoard(int dest[MAX][MAX], int src[MAX][MAX], int size);
void initSolvedBoard(int board[MAX][MAX], int size);
void shuffleBoard(int board[MAX][MAX], int size, int *blankR, int *blankC);
void printBoard(int board[MAX][MAX], int size);
int moveBlank(int board[MAX][MAX], int size, int *blankR, int *blankC, char cmd);
int isSolved(int board[MAX][MAX], int size);
void replayGame(int initialBoard[MAX][MAX], int size, char moves[], int moveCount);
void saveGame(SaveData *data);
int loadGame(SaveData *data);
void addRanking(const char *name, int size, int moveCount, int seconds);
void showRanking();
char tileToChar(int value);

void copyBoard(int dest[MAX][MAX], int src[MAX][MAX], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

void initSolvedBoard(int board[MAX][MAX], int size) {
    int i, j, num = 1;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j] = num++;
        }
    }
    board[size - 1][size - 1] = 0; // blank
}

int moveBlank(int board[MAX][MAX], int size, int *blankR, int *blankC, char cmd) {
    int nr = *blankR;
    int nc = *blankC;
    int temp;

    if (cmd == 'w') nr--;
    else if (cmd == 's') nr++;
    else if (cmd == 'a') nc--;
    else if (cmd == 'd') nc++;
    else return 0;

    if (nr < 0 || nr >= size || nc < 0 || nc >= size) return 0;

    temp = board[*blankR][*blankC];
    board[*blankR][*blankC] = board[nr][nc];
    board[nr][nc] = temp;

    *blankR = nr;
    *blankC = nc;
    return 1;
}

void shuffleBoard(int board[MAX][MAX], int size, int *blankR, int *blankC) {
    int i;
    char dirs[4] = {'w', 'a', 's', 'd'};
    char cmd;

    initSolvedBoard(board, size);
    *blankR = size - 1;
    *blankC = size - 1;

    srand((unsigned int)time(NULL));

    for (i = 0; i < 300; i++) {
        cmd = dirs[rand() % 4];
        moveBlank(board, size, blankR, blankC, cmd);
    }
}

char tileToChar(int value) {
    if (value == 0) return ' ';
    return 'A' + value - 1;
}

void printBoard(int board[MAX][MAX], int size) {
    int i, j;

    printf("\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("+---");
        }
        printf("+\n");

        for (j = 0; j < size; j++) {
            if (board[i][j] == 0)
                printf("|   ");
            else
                printf("| %c ", tileToChar(board[i][j]));
        }
        printf("|\n");
    }

    for (j = 0; j < size; j++) {
        printf("+---");
    }
    printf("+\n");
}

int isSolved(int board[MAX][MAX], int size) {
    int i, j, num = 1;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == size - 1 && j == size - 1) {
                if (board[i][j] != 0) return 0;
            } else {
                if (board[i][j] != num) return 0;
                num++;
            }
        }
    }
    return 1;
}

void replayGame(int initialBoard[MAX][MAX], int size, char moves[], int moveCount) {
    int board[MAX][MAX];
    int i, j;
    int blankR = 0, blankC = 0;

    copyBoard(board, initialBoard, size);

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                blankR = i;
                blankC = j;
            }
        }
    }

    printf("\n=== REPLAY START ===\n");
    printBoard(board, size);

    for (i = 0; i < moveCount; i++) {
        printf("\n%d번째 이동: %c\n", i + 1, moves[i]);
        moveBlank(board, size, &blankR, &blankC, moves[i]);
        printBoard(board, size);
    }

    printf("\n=== REPLAY END ===\n");
}

void saveGame(SaveData *data) {
    FILE *fp = fopen(SAVE_FILE, "wb");
    if (fp == NULL) {
        printf("저장 실패\n");
        return;
    }

    fwrite(data, sizeof(SaveData), 1, fp);
    fclose(fp);
    printf("게임이 저장되었습니다.\n");
}

int loadGame(SaveData *data) {
    FILE *fp = fopen(SAVE_FILE, "rb");
    if (fp == NULL) {
        return 0;
    }

    fread(data, sizeof(SaveData), 1, fp);
    fclose(fp);
    return 1;
}

void addRanking(const char *name, int size, int moveCount, int seconds) {
    RankRecord records[11];
    RankRecord newRecord;
    FILE *fp;
    int count = 0, i, j;

    strcpy(newRecord.name, name);
    newRecord.size = size;
    newRecord.moveCount = moveCount;
    newRecord.seconds = seconds;

    fp = fopen(RANK_FILE, "rb");
    if (fp != NULL) {
        while (fread(&records[count], sizeof(RankRecord), 1, fp) == 1 && count < 10) {
            count++;
        }
        fclose(fp);
    }

    records[count++] = newRecord;

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (records[i].seconds > records[j].seconds) {
                RankRecord temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }

    if (count > 10) count = 10;

    fp = fopen(RANK_FILE, "wb");
    if (fp == NULL) {
        printf("랭킹 저장 실패\n");
        return;
    }

    fwrite(records, sizeof(RankRecord), count, fp);
    fclose(fp);
}

void showRanking() {
    FILE *fp = fopen(RANK_FILE, "rb");
    RankRecord r;
    int rank = 1;

    if (fp == NULL) {
        printf("\n랭킹 파일이 없습니다.\n");
        return;
    }

    printf("\n=== TOP 10 RANKING ===\n");
    while (fread(&r, sizeof(RankRecord), 1, fp) == 1) {
        printf("%d위 | 이름: %s | 크기: %dx%d | 이동수: %d | 시간: %d초\n",
               rank, r.name, r.size, r.size, r.moveCount, r.seconds);
        rank++;
    }

    fclose(fp);
}

int main() {
    SaveData game;
    int choice;
    char cmd;
    char name[20];
    int finished = 0;

    printf("==== 퍼즐 게임 ====\n");
    printf("1. 새 게임\n");
    printf("2. 저장된 게임 이어하기\n");
    printf("3. 랭킹 보기\n");
    printf("선택: ");
    scanf("%d", &choice);

    if (choice == 3) {
        showRanking();
        return 0;
    }

    if (choice == 2) {
        if (!loadGame(&game)) {
            printf("저장된 게임이 없습니다. 새 게임으로 시작합니다.\n");
            choice = 1;
        } else {
            printf("저장된 게임을 불러왔습니다.\n");
        }
    }

    if (choice == 1) {
        printf("퍼즐 크기 선택 (3 / 4 / 5): ");
        scanf("%d", &game.size);

        if (game.size < 3 || game.size > 5) {
            printf("잘못된 크기입니다.\n");
            return 0;
        }

        shuffleBoard(game.board, game.size, &game.blankR, &game.blankC);
        copyBoard(game.initialBoard, game.board, game.size);
        game.moveCount = 0;
        game.elapsedBeforeSave = 0;
        game.startTime = time(NULL);
    } else if (choice == 2) {
        game.startTime = time(NULL) - game.elapsedBeforeSave;
    }

    while (!finished) {
        int elapsed = (int)(time(NULL) - game.startTime);

        printf("\n현재 시간: %d초 | 이동 횟수: %d\n", elapsed, game.moveCount);
        printBoard(game.board, game.size);
        printf("이동(w/a/s/d), 저장(x), 종료(q): ");
        scanf(" %c", &cmd);

        if (cmd == 'x') {
            game.elapsedBeforeSave = (int)(time(NULL) - game.startTime);
            saveGame(&game);
            printf("프로그램 종료\n");
            return 0;
        }

        if (cmd == 'q') {
            printf("프로그램 종료\n");
            return 0;
        }

        if (moveBlank(game.board, game.size, &game.blankR, &game.blankC, cmd)) {
            if (game.moveCount < MAX_MOVES) {
                game.moves[game.moveCount] = cmd;
            }
            game.moveCount++;

            if (isSolved(game.board, game.size)) {
                int totalTime = (int)(time(NULL) - game.startTime);
                printf("\n퍼즐 완성!\n");
                printf("총 이동 횟수: %d\n", game.moveCount);
                printf("총 시간: %d초\n", totalTime);

                printf("이름 입력: ");
                scanf("%s", name);
                addRanking(name, game.size, game.moveCount, totalTime);

                printf("\n리플레이를 보시겠습니까? (y/n): ");
                scanf(" %c", &cmd);
                if (cmd == 'y') {
                    replayGame(game.initialBoard, game.size, game.moves, game.moveCount);
                }

                finished = 1;
            }
        } else {
            printf("이동 불가!\n");
        }
    }

    return 0;
}