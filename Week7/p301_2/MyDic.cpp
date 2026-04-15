// #include <iostream>
// #include <string>
// using namespace std;

// struct WordPair {
//     string eng;
//     string kor;
// };

// class MyDic {
//     // 배열 + nWords
//     // add, load, store, print, getEng, getKor
// };

// int main() {
//     // 테스트 (add, print, load, store)
// }


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAXWORDS 100

struct WordPair {
    string eng;
    string kor;
};

class MyDic {
    WordPair words[MAXWORDS];   // 저장된 단어 배열
    int nWords;                 // 현재 등록된 단어 수

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

    void store(string filename) {
        ofstream fout(filename);

        if (!fout) {
            cout << "파일을 만들 수 없습니다: " << filename << endl;
            return;
        }

        for (int i = 0; i < nWords; i++) {
            fout << words[i].eng << " " << words[i].kor << endl;
        }

        fout.close();
    }

    void print() {
        cout << "---- 단어장 출력 ----" << endl;
        for (int i = 0; i < nWords; i++) {
            cout << i << ": " << words[i].eng << " - " << words[i].kor << endl;
        }
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
};

int main() {
    MyDic dic;

    dic.add("apple", "사과");
    dic.add("banana", "바나나");
    dic.add("grape", "포도");

    dic.print();

    dic.store("dic.txt");

    MyDic dic2;
    dic2.load("dic.txt");

    cout << endl;
    cout << "파일에서 다시 불러온 결과" << endl;
    dic2.print();

    cout << endl;
    cout << "0번 영어: " << dic2.getEng(0) << endl;
    cout << "0번 뜻: " << dic2.getKor(0) << endl;

    return 0;
}