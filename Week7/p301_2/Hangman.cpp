#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAXWORDS 100

struct WordPair {
    string eng;
    string kor;
};

class MyDic {
    WordPair words[MAXWORDS];
    int nWords;

public:
    MyDic() {
        nWords = 0;
    }

    void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        }
    }

    void load(string filename) {
        ifstream fin(filename);

        if (!fin) {
            cout << "파일을 열 수 없습니다: " << filename << endl;
            return;
        }

        nWords = 0;

        string eng, kor;
        while (fin >> eng >> kor) {
            add(eng, kor);
        }

        fin.close();
    }

    string getEng(int id) {
        if (id >= 0 && id < nWords)
            return words[id].eng;
        return "";
    }

    string getKor(int id) {
        if (id >= 0 && id < nWords)
            return words[id].kor;
        return "";
    }

    int getSize() {
        return nWords;
    }
};

int main() {
    MyDic dic;
    dic.load("dic.txt");

    if (dic.getSize() == 0) {
        cout << "단어장이 비어 있습니다." << endl;
        return 0;
    }

    srand(time(0));

    int index = rand() % dic.getSize();
    string word = dic.getEng(index);
    string meaning = dic.getKor(index);

    string guess;
    int chance = 5;

    cout << "행맨 게임 시작!" << endl;

    while (chance > 0) {
        cout << "영어 단어를 맞혀보세요: ";
        cin >> guess;

        if (guess == word) {
            cout << "정답!" << endl;
            break;
        } else {
            chance--;
            cout << "틀렸습니다. 남은 기회: " << chance << endl;
        }
    }

    cout << "정답 단어: " << word << endl;
    cout << "한글 뜻: " << meaning << endl;

    return 0;
}