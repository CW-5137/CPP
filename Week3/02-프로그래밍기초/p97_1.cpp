#include <iostream>
using namespace std;

int main() {

    cout << "(1)번" << endl;
    for(int i=1; i<=5; i++){
        for(int j=1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "(2)번" << endl;
    for(int i=5; i>=1; i--){
        for(int j=5; j>=6-i; j--){
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "(3)번" << endl;
    for(int i=1; i<=5; i++){

    // 공백 
    for(int k=1; k<=5-i; k++){
        cout << "  ";
    }

    // 숫자 출력
    for(int j=i; j>=1; j--){
        cout << j << " ";
    }

    cout << endl;
}

    cout << "(4)번" << endl;
    for(int i=1; i<=5; i++){

    // 공백 출력
    for(int k=1; k<=5-i; k++){
        cout << "  ";
    }

    // 감소
    for(int j=i; j>=1; j--){
        cout << j << " ";
    }

    // 증가
    for(int j=2; j<=i; j++){
        cout << j << " ";
    }

    cout << endl;
}
    return 0;
}