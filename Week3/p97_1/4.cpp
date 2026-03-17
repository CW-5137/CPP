#include <iostream>
using namespace std;

int main() {
    for(int i=1; i<=5; i++){

        // 공백
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